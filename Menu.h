/*
* �˵��ӿ�
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
* ���˵�
* @param connection ���ݿ�����
*/
void mainMenu(_ConnectionPtr connection);

/*
* �˵�-ѧ���ɼ�����
* @param connection ���ݿ�����
*/
void studentGradeMenu(_ConnectionPtr connection);

/*
* �˵�-ѧ���ɼ�����-������չ�˵�
* @param connection ���ݿ�����
*/
void studentGradeExternMenu(_ConnectionPtr connection);

/*
* �˵�-�γ̹���
* @param connection ���ݿ�����
*/
void courseMenu(_ConnectionPtr connection);

/*
* �߼����ܣ�ִ���û����������SQL��䣩
* @param connection ���ݿ�����
*/
void advancedFunction(_ConnectionPtr connection);

/*
* ��ʾ����ѧ��
* @param connection ���ݿ�����
*/
void showAllStudent(_ConnectionPtr connection);

/*
* ����ѧ��
* @param connection ���ݿ�����
*/
void insertStudent(_ConnectionPtr connection);

/*
* ɾ��ѧ��
* @param connection ���ݿ�����
*/
void deleteStudent(_ConnectionPtr connection);

/*
* �޸�ѧ��
* @param connection ���ݿ�����
*/
void changeStudent(_ConnectionPtr connection);

/*
* �˵�-��������
* @param connection ���ݿ�����
*/
void exportData(_ConnectionPtr connection);

/*
* ����ѧ������
* @param connection ���ݿ�����
*/
void exportStudentData(_ConnectionPtr connection);

/*
* �����γ�����
* @param connection ���ݿ�����
*/
void exportCourseData(_ConnectionPtr connection);

/*
* �����ɼ�����
* @param connection ���ݿ�����
*/
void exportGradeData(_ConnectionPtr connection);

/*
* ������������
* @param connection ���ݿ�����
*/
void exportAllData(_ConnectionPtr connection);

/*
* �˵�-��������
* @param connection ���ݿ�����
*/
void importData(_ConnectionPtr connection);

/*
* ����ѧ������
* @param connection ���ݿ�����
*/
void importStudentData(_ConnectionPtr connection);

/*
* ����γ�����
* @param connection ���ݿ�����
*/
void importCourseData(_ConnectionPtr connection);

/*
* ����ɼ�����
* @param connection ���ݿ�����
*/
void importGradeData(_ConnectionPtr connection);

/*
* ������������
* @param connection ���ݿ�����
*/
void importAllData(_ConnectionPtr connection);

#endif // !MENU_H