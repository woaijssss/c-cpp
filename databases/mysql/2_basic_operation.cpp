
#include <iostream>

#include "pub/MysqlConnector.h"

using namespace std;

static int user_id = 0;
static long telNum = 18301418250;

MYSQL_RES* insert(MysqlConnector& mc, const string& table)
{
	string username = "wenhan_" + to_string(user_id++);
	string tel = to_string(telNum++);
	string cmd = "insert into " + table + " (name,tel) values ('" + username + "','" + tel+ "')";
	cout << cmd << endl;
	
	return mc.execSqlCmd(cmd.c_str());
}

MYSQL_RES* select(MysqlConnector& mc, const string& table)
{
	string username = "wenhan_8";
	//string tel = to_string(telNum);
	string cmd = "select * from " + table + " where name='" + username + "'";
	
	return mc.execSqlCmd(cmd.c_str());
}

MYSQL_RES* update(MysqlConnector& mc, const string& table)
{
	string username = "wenhan_8";
	string tel = to_string(66666666666);
	string cmd = "update " + table + " set tel='" + tel + "' where name='" + username + "'";
	
	return mc.execSqlCmd(cmd.c_str());
}

MYSQL_RES* del(MysqlConnector& mc, const string& table)
{
	string username = "wenhan_8";
	//string tel = to_string(telNum);
	string cmd = "delete from " + table + " where name='" + username + "'";
	
	return mc.execSqlCmd(cmd.c_str());
}

/*
 * 测试表：
 * 	create table people (id int auto_increment, name varchar(100) not null, tel varchar(32) not null, reg_date timestamp null default current_timestamp on update current_timestamp, primary key (id));
 * 	如此创建表，可以使：
 *		（1）插入(insert)时，自动添加当前时间；
 *		（2）更新(update)时，自动更新当前时间；
 * 编译项：
 *	g++ 2_basic_operation.cpp -Ipub/ -I/usr/include/mysql -Lpub/ -lmysqlconnector -std=c++11
 */
int main()
{
	MysqlConnInfo myConn = {
		"192.168.12.250",
		"TEST",
		"admin",
		"123456"
	};
	
	MysqlConnector mc;
	
	if (mc.connect(myConn))
	{
		cout << "connect success" << endl;
		
		// insert
#if 0
		for (int i = 0 ; i < 10; i++)
		{
			MYSQL_RES* res = insert(mc, "people");
		}
#endif

		// select
		MYSQL_RES* res = select(mc, "people");
		if (res)
		{			
			while (MYSQL_ROW row = mc.fetchRow(res))	// 二维数组
			{
				int cols = mc.getColCount(res);
				
				// row已经标识每一行，这里按照列操作遍历
				for (int i = 0; i < cols; i++) 
				{
					cout << row[i] << ", ";
				}
				cout << endl;
			}
		}
		
		// update
#if 0
		{
			MYSQL_RES* res = update(mc, "people");
			cout << res << endl;
		}
#endif
		
		// delete
#if 0
		{
			MYSQL_RES* res = del(mc, "people");
			cout << res << endl;
		}
#endif

		mc.disconnect();
	}
	else
	{
		cout << "connect failed" << endl;
	}
	
	
	return 0;
}