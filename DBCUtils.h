/*
* ���ݿ����ӹ��ߺ����ӿ�
*/
#ifndef DBCUTILS_H
#define DBCUTILS_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include <stdio.h>  // wprintf
#include <iostream>
#include <locale.h> // setlocale
#include <string>

/*
* ��ȡ����
* @param pwd ����֤������
* @param connection ����ȡ�����Ӷ���
* @return bool �����Ƿ���ȷ / �Ƿ��ȡ������
*/
bool getConnection(std::string& pwd, _ConnectionPtr& connection);

/*
* ��ȡsql�������
* @param sql ����ȡ�������SQL���
* @param comType SQL������
*/
void getSqlType(std::string& sql, std::string& comType);

#endif // !DBCUTILS_H