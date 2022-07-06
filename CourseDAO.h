/*
* �γ̱����ݿ�����ӿ�
*/
#ifndef COURSE_DAO_H
#define COURSE_DAO_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include<iostream>
#include<vector>
#include"Course.h"
#include"BaseDAO.h"

/*
* �����ݿ���ӿγ�
* @param connection ���ݿ�����
* @param course ����ӵĿγ̶���
*/
void addCourse(_ConnectionPtr connection, Course course);

/*
* ɾ���γ�
* @param connection ���ݿ�����
* @param id �γ̺�
*/
void deleteCourse(_ConnectionPtr connection, string id);

/*
* �޸Ŀγ���
* @param connection ���ݿ�����
* @param id �γ̺�
* @param name �γ���
*/
void updateCourseName(_ConnectionPtr connection, string id, string name);

/*
* ���ݿγ̺Ż�ȡ�γ̶���
* @param connection ���ݿ�����
* @param id �γ̺�
* @return Course* course����ָ��
*/
Course* getCourseById(_ConnectionPtr connection, string id);

/*
* ���ݿγ�����ȡ�γ̶���
* @param connection ���ݿ�����
* @param name �γ���
* @return Course* course����ָ��
*/
Course* getCourseByName(_ConnectionPtr connection, string name);

/*
* ��ȡ���пγ̶���
* @param connection ���ݿ�����
* @return vector<Course>* ��Course����ΪԪ�ص�vector����ָ��
*/
std::vector<Course>* getAllCourse(_ConnectionPtr connection);

#endif // !COURSE_DAO_H