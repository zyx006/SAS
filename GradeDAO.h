#ifndef GRADE_DAO_H
#define GRADE_DAO_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include<iostream>
#include<vector>
#include"Grade.cpp"

void addGrade(_ConnectionPtr connection, Grade grade);
void deleteOnesGrade(_ConnectionPtr connection, string stuId,string courseId);
void deleteGradeByStuId(_ConnectionPtr connection, string stuId);
void deleteGradeByCourseId(_ConnectionPtr connection, string courseId);
void updateOnesGrade(_ConnectionPtr connection, string stuId, string courseId, string grade);
Grade* getOnesGrade(_ConnectionPtr connection, string stuId, string courseId);
std::vector<Grade>* getGradeByStuId(_ConnectionPtr connection, string stuId);
std::vector<Grade>* getGradeByCourseId(_ConnectionPtr connection, string courseId);
std::vector<Grade>* getGradeByStuClass(_ConnectionPtr connection, string stuClass);
std::vector<Grade>* getAllGrade(_ConnectionPtr connection);

double getOnesAvgGrade(_ConnectionPtr connection, string stuId);
double getOnesAllGrade(_ConnectionPtr connection, string stuId);
double getClassAvgGrade(_ConnectionPtr connection, string stuClass, string courseName);
double getClassMaxGrade(_ConnectionPtr connection, string stuClass, string courseName);
double getClassMinGrade(_ConnectionPtr connection, string stuClass, string courseName);

#endif // !GRADE_DAO_H
