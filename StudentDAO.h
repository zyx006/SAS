#ifndef STUDENT_DAO_H
#define STUDENT_DAO_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include<iostream>
#include<vector>
#include"Student.cpp"

void addStudent(_ConnectionPtr connection, Student student);
void deleteStudent(_ConnectionPtr connection, string id);
void updateStudentClass(_ConnectionPtr connection, string id, string stuClass);
void updateStudentStatus(_ConnectionPtr connection, string id, string status);
Student* getStudentById(_ConnectionPtr connection, string id);
std::vector<Student>* getStudentByName(_ConnectionPtr connection, string name);
std::vector<Student>* getAllStudent(_ConnectionPtr connection);

#endif // !STUDENT_DAO_H