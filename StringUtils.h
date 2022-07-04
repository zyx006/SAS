#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#define _CRT_SECURE_NO_WARNINGS

#include<string>
using std::string;

/*
* 将double型数据转换为字符串并返回
* @param num 待转换的double型数据
* @return string 转换后的字符串
*/
string doubleToString(double num);

/*
* 去除字符串首尾空格
* @param str 待去除空格的字符串
* @return string 去除空格后的字符串
*/
std::string trim(const std::string& str);

/*
* 去除字符串首尾空格及中间多余空格
* @param str 待去除空格的字符串
* @return string 去除空格后的字符串
*/
std::string reduce(const std::string& str);

#endif // !STRING_UTILS_H
