/*
* ���ݿ���������ӿ�
*/
#ifndef BASE_DAO_H
#define BASE_DAO_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
* �Բ�����sql�����в�����䲢ִ��
* @param connection ���ݿ�����
* @param sql ������ִ�е�sql���
* @param v Ҫ���Ĳ������޲�������NULL��
* @return _RecordsetPtr ���ؼ�¼��ָ��
*/
_RecordsetPtr executeSql(_ConnectionPtr connection, const char* sql, vector<string>* v);

#endif // !BASE_DAO_H