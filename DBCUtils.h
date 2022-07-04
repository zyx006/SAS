/*
* 数据库连接工具函数接口
*/
#ifndef DBCUTILS_H
#define DBCUTILS_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include <stdio.h>  // wprintf
#include <iostream>
#include <locale.h> // setlocale
#include <string>

/*
* 获取连接
* @param pwd 待验证的密码
* @param connection 待获取的连接对象
* @return bool 密码是否正确 / 是否获取到连接
*/
bool getConnection(std::string& pwd, _ConnectionPtr& connection);

/*
* 获取sql语句种类
* @param sql 待获取语句类别的SQL语句
* @param comType SQL语句类别
*/
void getSqlType(std::string& sql, std::string& comType);

#endif // !DBCUTILS_H