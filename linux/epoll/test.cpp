#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <sys/epoll.h>

#include <iostream>
using namespace std;

static int startEpoll(const int& sock_fd)
{
	int epoll_fd = epoll_create(1024);
	if (epoll_fd < 0)
	{
		cerr << "fail to create epoll, err: " << strerror(errno) << endl;
		return -1;
	}
	
	epoll_event event;
	event.events = EPOLLIN;
	event.data.fd = sock_fd;
	if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sock_fd, &event) < 0)
	{
		cerr << "fail to add listen fd to epoll, err: " << strerror(errno) << endl;
		return -1;
	}
	
	epoll_event events[1024];
	uint8_t recvBuf[1024*1024] = {0};
	
	while (true)
	{
		int fd_count = epoll_wait(epoll_fd, events, 1024, -1);
		if (fd_count < 0)
		{
			cerr << "epoll wait error, err: " << strerror(errno) << endl;
			return -1;
		}
		
		for (int i = 0; i < fd_count; i++)
		{
			if (events[i].data.fd == sock_fd)	// 说明当前的描述符是一个监听socket
			{
				sockaddr_in client_addr;
				socklen_t addr_len = sizeof(client_addr);
				int accept_fd = accept(sock_fd, (sockaddr*)&client_addr, &addr_len);
				if (accept_fd < 0)
				{
					cerr << "fail to accpet, err: " << strerror(errno) << endl;
					continue;
				}
				cout << "recv connection from " << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << endl;
				
				event.events = EPOLLIN;
				event.data.fd = accept_fd;
				if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, accept_fd, &event) < 0)
				{
					close(accept_fd);
					cerr << "fail to add fd to epoll, err: " << strerror(errno) << endl;
					continue;
				}
			}
			else	// 以下步骤将处理业务socket
			{
				int cur_fd = events[i].data.fd;
				size_t recv_len = recv(cur_fd, recvBuf, sizeof(recvBuf), 0);
				if (recv_len < 0)
				{
					cerr << "fail to recv, close connection, err: " << strerror(errno) << endl;
				
					if (epoll_ctl(epoll_fd, EPOLL_CTL_DEL, cur_fd, NULL) < 0)
					{
						cerr << "fail to del fd from epoll, err: " << strerror(errno) << endl;
					}
					close(cur_fd);
					continue;
				}
				
				if (recv_len == 0)
				{
					cout << "connection closed by client" << endl;
					if (epoll_ctl(epoll_fd, EPOLL_CTL_DEL, cur_fd, NULL) < 0)
					{
						cerr << "fail to del fd from epoll, err: " << strerror(errno) << endl;
					}
					close(cur_fd);
					continue;
				}
				
				cout << "recv data len: " << recv_len << endl;
				for (int i = 0; i < recv_len; i++)
				{
					printf("%02x ", recvBuf[i]);
				}
				cout << endl;
			}
		}
	}
	
	
}

int main()
{
	int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	if (sock_fd < 0)
	{
		cerr << "fail to create socket, err: " << strerror(errno) << endl;
		return -1;
	}
	
	sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	addr.sin_port = htons(20001);
	
	if (bind(sock_fd, (sockaddr*)&addr, sizeof(addr)) < 0)
	{
		cerr << "fail to bind addr  err: " << strerror(errno) << endl;
		return -1;
	}
	
	if (listen(sock_fd, 100) < 0)
	{
		cerr << "fail to listen on err: " << strerror(errno) << endl;
		return -1;
	}
	
	
	if (startEpoll(sock_fd) < 0)
	{
		return -1;
	}
	
	return 0;
}