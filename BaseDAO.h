/*
* 数据库操作基础接口
*/
#ifndef BASE_DAO_H
#define BASE_DAO_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
* 对参数化sql语句进行参数填充并执行
* @param connection 数据库连接
* @param sql 待填充和执行的sql语句
* @param v 要填充的参数（无参数则传入NULL）
* @return _RecordsetPtr 返回记录集指针
*/
_RecordsetPtr executeSql(_ConnectionPtr connection, const char* sql, vector<string>* v);

#endif // !BASE_DAO_H