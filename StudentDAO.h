/*
* 学生表数据库操作接口
*/
#ifndef STUDENT_DAO_H
#define STUDENT_DAO_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include<iostream>
#include<vector>
#include"Student.cpp"

/*
* 向数据库添加学生
* @param connection 数据库连接
* @param student 待添加的学生对象
*/
void addStudent(_ConnectionPtr connection, Student student);

/*
* 删除学生
* @param connection 数据库连接
* @param id 学号
*/
void deleteStudent(_ConnectionPtr connection, string id);

/*
* 修改学生班级
* @param connection 数据库连接
* @param id 学号
* @param stuClass 新班级
*/
void updateStudentClass(_ConnectionPtr connection, string id, string stuClass);

/*
* 修改学生状态
* @param connection 数据库连接
* @param id 学号
* @param status 学生状态（在读、休学、退学）
*/
void updateStudentStatus(_ConnectionPtr connection, string id, string status);

/*
* 根据学号获取学生对象
* @param connection 数据库连接
* @param id 学号
* @return Student* student对象指针
*/
Student* getStudentById(_ConnectionPtr connection, string id);

/*
* 根据姓名获取学生对象
* @param connection 数据库连接
* @param name 姓名
* @return vector<Student>* 以Student对象为元素的vector数组指针
*/
std::vector<Student>* getStudentByName(_ConnectionPtr connection, string name);

/*
* 获取所有学生
* @param connection 数据库连接
* @return vector<Student>* 以Student对象为元素的vector数组指针
*/
std::vector<Student>* getAllStudent(_ConnectionPtr connection);

#endif // !STUDENT_DAO_H