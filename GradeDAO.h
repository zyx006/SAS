/*
* 成绩表数据库操作接口
*/
#ifndef GRADE_DAO_H
#define GRADE_DAO_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include<iostream>
#include<vector>
#include"Grade.h"
#include"BaseDAO.h"

/*
* 向数据库添加成绩
* @param connection 数据库连接
* @param grade 待添加的成绩对象
*/
void addGrade(_ConnectionPtr connection, Grade grade);

/*
* 删除某人的某科成绩
* @param connection 数据库连接
* @param stuId 学号
* @param courseId 课程号
*/
void deleteOnesGrade(_ConnectionPtr connection, string stuId,string courseId);

/*
* 删除某人所有成绩
* @param connection 数据库连接
* @param stuId 学号
*/
void deleteGradeByStuId(_ConnectionPtr connection, string stuId);

/*
* 删除某科的所有成绩
* @param connection 数据库连接
* @param courseId 待删除课程的课程号
*/
void deleteGradeByCourseId(_ConnectionPtr connection, string courseId);

/*
* 更新某人的某科成绩
* @param connection 数据库连接
* @param stuId 学号
* @param courseId 课程号
* @param grade 成绩
*/
void updateOnesGrade(_ConnectionPtr connection, string stuId, string courseId, string grade);

/*
* 获取某人某科成绩
* @param connection 数据库连接
* @param stuId 学号
* @param courseId 课程号
* @return Grade* grade对象指针
*/
Grade* getOnesGrade(_ConnectionPtr connection, string stuId, string courseId);

/*
* 获取某人的所有成绩
* @param connection 数据库连接
* @param stuId 学号
* @return vector<Grade>* 以Grade对象为元素的vector数组指针
*/
std::vector<Grade>* getGradeByStuId(_ConnectionPtr connection, string stuId);

/*
* 获取某课程的所有成绩记录
* @param connection 数据库连接
* @param coursesId 课程号
* @return vector<Grade>* 以Grade对象为元素的vector数组指针
*/
std::vector<Grade>* getGradeByCourseId(_ConnectionPtr connection, string courseId);

/*
* 获取某班级的所有成绩记录
* @param connection 数据库连接
* @param stuClass 班级
* @return vector<Grade>* 以Grade对象为元素的vector数组指针
*/
std::vector<Grade>* getGradeByStuClass(_ConnectionPtr connection, string stuClass);

/*
* 获取所有成绩记录
* @param connection 数据库连接
* @return vector<Grade>* 以Grade对象为元素的vector数组指针
*/
std::vector<Grade>* getAllGrade(_ConnectionPtr connection);

/*
* 获取某人的平均成绩
* @param connection 数据库连接
* @param stuId 学号
* @return double 平均成绩
*/
double getOnesAvgGrade(_ConnectionPtr connection, string stuId);

/*
* 获取某人的总成绩
* @param connection 数据库连接
* @param stuId 学号
* @return double 总成绩
*/
double getOnesAllGrade(_ConnectionPtr connection, string stuId);

/*
* 获取某班级某科的平均成绩
* @param connection 数据库连接
* @param stuClass 班级
* @param courseName 课程名
* @return double 班级某科平均成绩
*/
double getClassAvgGrade(_ConnectionPtr connection, string stuClass, string courseName);

/*
* 获取某班级某科的最高成绩
* @param connection 数据库连接
* @param stuClass 班级
* @param courseName 课程名
* @return double 班级某科最高成绩
*/
double getClassMaxGrade(_ConnectionPtr connection, string stuClass, string courseName);

/*
* 获取某班级某科的最低成绩
* @param connection 数据库连接
* @param stuClass 班级
* @param courseName 课程名
* @return double 班级某科最低成绩
*/
double getClassMinGrade(_ConnectionPtr connection, string stuClass, string courseName);

#endif // !GRADE_DAO_H
