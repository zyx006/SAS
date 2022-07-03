#ifndef MENU_H
#define MENU_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include<vector>
#include"Student.cpp"
#include"Course.cpp"
#include"Grade.cpp"

void mainMenu(_ConnectionPtr connection);
void studentGradeMenu(_ConnectionPtr connection);
void studentGradeExternMenu(_ConnectionPtr connection);
void courseMenu(_ConnectionPtr connection);

void showAllStudent(_ConnectionPtr connection);
void insertStudent(_ConnectionPtr connection);
void deleteStudent(_ConnectionPtr connection);
void changeStudent(_ConnectionPtr connection);

void exportData(_ConnectionPtr connection);
void importData(_ConnectionPtr connection);

#endif // !MENU_H