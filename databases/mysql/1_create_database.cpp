
#include <iostream>

#include "pub/MysqlConnector.h"

using namespace std;


/*
 * 测试创建数据库、创建表
 * 		实际中一般不会在服务器应用中，动态的创建和删除库、表；
 */
int main()
{
	MysqlConnInfo myConn = {
		"192.168.12.250",
		"test",
		"admin",
		"123456"
	};
	
	MysqlConnector mc;
	
	if (mc.connect(myConn))
	{
		cout << "connect success" << endl;
		MYSQL_RES* mRes = mc.execSqlCmd("create DATABASE TEST");
	
		mc.disconnect();
	}
	else
	{
		cout << "connect failed" << endl;
	}
	
	
	return 0;
}