/*
* 菜单接口
*/
#ifndef MENU_H
#define MENU_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include<iostream>
#include<fstream>
#include<vector>
#include<direct.h>
#include<io.h>

#include"Student.cpp"
#include"Course.cpp"
#include"Grade.cpp"
#include"DBCUtils.h"
#include"MenuUtils.h"
#include"StringUtils.h"
#include"StudentDAO.h"
#include"GradeDAO.h"
#include"CourseDAO.h"
using namespace std;

/*
* 主菜单
* @param connection 数据库连接
*/
void mainMenu(_ConnectionPtr connection);

/*
* 菜单-学生成绩管理
* @param connection 数据库连接
*/
void studentGradeMenu(_ConnectionPtr connection);

/*
* 菜单-学生成绩管理-二级拓展菜单
* @param connection 数据库连接
*/
void studentGradeExternMenu(_ConnectionPtr connection);

/*
* 菜单-课程管理
* @param connection 数据库连接
*/
void courseMenu(_ConnectionPtr connection);

/*
* 高级功能（执行用户输入的任意SQL语句）
* @param connection 数据库连接
*/
void advancedFunction(_ConnectionPtr connection);

/*
* 显示所有学生
* @param connection 数据库连接
*/
void showAllStudent(_ConnectionPtr connection);

/*
* 增加学生
* @param connection 数据库连接
*/
void insertStudent(_ConnectionPtr connection);

/*
* 删除学生
* @param connection 数据库连接
*/
void deleteStudent(_ConnectionPtr connection);

/*
* 修改学生
* @param connection 数据库连接
*/
void changeStudent(_ConnectionPtr connection);

/*
* 菜单-导出数据
* @param connection 数据库连接
*/
void exportData(_ConnectionPtr connection);

/*
* 导出学生数据
* @param connection 数据库连接
*/
void exportStudentData(_ConnectionPtr connection);

/*
* 导出课程数据
* @param connection 数据库连接
*/
void exportCourseData(_ConnectionPtr connection);

/*
* 导出成绩数据
* @param connection 数据库连接
*/
void exportGradeData(_ConnectionPtr connection);

/*
* 导出所有数据
* @param connection 数据库连接
*/
void exportAllData(_ConnectionPtr connection);

/*
* 菜单-导入数据
* @param connection 数据库连接
*/
void importData(_ConnectionPtr connection);

/*
* 导入学生数据
* @param connection 数据库连接
*/
void importStudentData(_ConnectionPtr connection);

/*
* 导入课程数据
* @param connection 数据库连接
*/
void importCourseData(_ConnectionPtr connection);

/*
* 导入成绩数据
* @param connection 数据库连接
*/
void importGradeData(_ConnectionPtr connection);

/*
* 导入所有数据
* @param connection 数据库连接
*/
void importAllData(_ConnectionPtr connection);

#endif // !MENU_H