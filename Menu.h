#ifndef MENU_H
#define MENU_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include<iostream>
#include<fstream>
#include<vector>
#include"Student.cpp"
#include"Course.cpp"
#include"Grade.cpp"
#include"DBCUtils.h"
#include"MenuUtils.h"
#include"StudentDAO.h"
#include"GradeDAO.h"
#include"CourseDAO.h"
using namespace std;

void mainMenu(_ConnectionPtr connection);
void studentGradeMenu(_ConnectionPtr connection);
void studentGradeExternMenu(_ConnectionPtr connection);
void courseMenu(_ConnectionPtr connection);
void advancedFunction(_ConnectionPtr connection);

void showAllStudent(_ConnectionPtr connection);
void insertStudent(_ConnectionPtr connection);
void deleteStudent(_ConnectionPtr connection);
void changeStudent(_ConnectionPtr connection);

void exportData(_ConnectionPtr connection);
void exportStudentData(_ConnectionPtr connection);
void exportCourseData(_ConnectionPtr connection);
void exportGradeData(_ConnectionPtr connection);
void exportAllData(_ConnectionPtr connection);

void importData(_ConnectionPtr connection);
void importStudentData(_ConnectionPtr connection);
void importCourseData(_ConnectionPtr connection);
void importGradeData(_ConnectionPtr connection);
void importAllData(_ConnectionPtr connection);

#endif // !MENU_H