/*
* 菜单工具接口
*/
#ifndef MENU_UTILS_H
#define MENU_UTILS_H

#include<stdio.h>
#include<iostream>
using namespace std;

/*
* 检查输入选项 opt∈[low,high]（opt∈Z）
* @param opt 输入的选项
* @param low 选项下限
* @param high 选项上限
*/
void checkOptInput(int& opt, int low, int high);

#endif // !MENU_UTILS_H
