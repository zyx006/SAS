#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#define _CRT_SECURE_NO_WARNINGS

#include<string>
using std::string;

/*
* ��double������ת��Ϊ�ַ���������
* @param num ��ת����double������
* @return string ת������ַ���
*/
string doubleToString(double num);

/*
* ȥ���ַ�����β�ո�
* @param str ��ȥ���ո���ַ���
* @return string ȥ���ո����ַ���
*/
std::string trim(const std::string& str);

/*
* ȥ���ַ�����β�ո��м����ո�
* @param str ��ȥ���ո���ַ���
* @return string ȥ���ո����ַ���
*/
std::string reduce(const std::string& str);

#endif // !STRING_UTILS_H
