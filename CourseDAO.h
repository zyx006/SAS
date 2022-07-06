/*
* 课程表数据库操作接口
*/
#ifndef COURSE_DAO_H
#define COURSE_DAO_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include<iostream>
#include<vector>
#include"Course.h"
#include"BaseDAO.h"

/*
* 向数据库添加课程
* @param connection 数据库连接
* @param course 待添加的课程对象
*/
void addCourse(_ConnectionPtr connection, Course course);

/*
* 删除课程
* @param connection 数据库连接
* @param id 课程号
*/
void deleteCourse(_ConnectionPtr connection, string id);

/*
* 修改课程名
* @param connection 数据库连接
* @param id 课程号
* @param name 课程名
*/
void updateCourseName(_ConnectionPtr connection, string id, string name);

/*
* 根据课程号获取课程对象
* @param connection 数据库连接
* @param id 课程号
* @return Course* course对象指针
*/
Course* getCourseById(_ConnectionPtr connection, string id);

/*
* 根据课程名获取课程对象
* @param connection 数据库连接
* @param name 课程名
* @return Course* course对象指针
*/
Course* getCourseByName(_ConnectionPtr connection, string name);

/*
* 获取所有课程对象
* @param connection 数据库连接
* @return vector<Course>* 以Course对象为元素的vector数组指针
*/
std::vector<Course>* getAllCourse(_ConnectionPtr connection);

#endif // !COURSE_DAO_H