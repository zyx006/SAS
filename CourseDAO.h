#ifndef COURSE_DAO_H
#define COURSE_DAO_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include<iostream>
#include<vector>
#include"Course.cpp"

void addCourse(_ConnectionPtr connection, Course course);
void deleteCourse(_ConnectionPtr connection, string id);
void updateCourseName(_ConnectionPtr connection, string id, string name);
Course* getCourseById(_ConnectionPtr connection, string id);
Course* getCourseByName(_ConnectionPtr connection, string name);
std::vector<Course>* getAllCourse(_ConnectionPtr connection);

#endif // !COURSE_DAO_H