/*
* �ɼ������ݿ�����ӿ�
*/
#ifndef GRADE_DAO_H
#define GRADE_DAO_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include<iostream>
#include<vector>
#include"Grade.h"
#include"BaseDAO.h"

/*
* �����ݿ���ӳɼ�
* @param connection ���ݿ�����
* @param grade ����ӵĳɼ�����
*/
void addGrade(_ConnectionPtr connection, Grade grade);

/*
* ɾ��ĳ�˵�ĳ�Ƴɼ�
* @param connection ���ݿ�����
* @param stuId ѧ��
* @param courseId �γ̺�
*/
void deleteOnesGrade(_ConnectionPtr connection, string stuId,string courseId);

/*
* ɾ��ĳ�����гɼ�
* @param connection ���ݿ�����
* @param stuId ѧ��
*/
void deleteGradeByStuId(_ConnectionPtr connection, string stuId);

/*
* ɾ��ĳ�Ƶ����гɼ�
* @param connection ���ݿ�����
* @param courseId ��ɾ���γ̵Ŀγ̺�
*/
void deleteGradeByCourseId(_ConnectionPtr connection, string courseId);

/*
* ����ĳ�˵�ĳ�Ƴɼ�
* @param connection ���ݿ�����
* @param stuId ѧ��
* @param courseId �γ̺�
* @param grade �ɼ�
*/
void updateOnesGrade(_ConnectionPtr connection, string stuId, string courseId, string grade);

/*
* ��ȡĳ��ĳ�Ƴɼ�
* @param connection ���ݿ�����
* @param stuId ѧ��
* @param courseId �γ̺�
* @return Grade* grade����ָ��
*/
Grade* getOnesGrade(_ConnectionPtr connection, string stuId, string courseId);

/*
* ��ȡĳ�˵����гɼ�
* @param connection ���ݿ�����
* @param stuId ѧ��
* @return vector<Grade>* ��Grade����ΪԪ�ص�vector����ָ��
*/
std::vector<Grade>* getGradeByStuId(_ConnectionPtr connection, string stuId);

/*
* ��ȡĳ�γ̵����гɼ���¼
* @param connection ���ݿ�����
* @param coursesId �γ̺�
* @return vector<Grade>* ��Grade����ΪԪ�ص�vector����ָ��
*/
std::vector<Grade>* getGradeByCourseId(_ConnectionPtr connection, string courseId);

/*
* ��ȡĳ�༶�����гɼ���¼
* @param connection ���ݿ�����
* @param stuClass �༶
* @return vector<Grade>* ��Grade����ΪԪ�ص�vector����ָ��
*/
std::vector<Grade>* getGradeByStuClass(_ConnectionPtr connection, string stuClass);

/*
* ��ȡ���гɼ���¼
* @param connection ���ݿ�����
* @return vector<Grade>* ��Grade����ΪԪ�ص�vector����ָ��
*/
std::vector<Grade>* getAllGrade(_ConnectionPtr connection);

/*
* ��ȡĳ�˵�ƽ���ɼ�
* @param connection ���ݿ�����
* @param stuId ѧ��
* @return double ƽ���ɼ�
*/
double getOnesAvgGrade(_ConnectionPtr connection, string stuId);

/*
* ��ȡĳ�˵��ܳɼ�
* @param connection ���ݿ�����
* @param stuId ѧ��
* @return double �ܳɼ�
*/
double getOnesAllGrade(_ConnectionPtr connection, string stuId);

/*
* ��ȡĳ�༶ĳ�Ƶ�ƽ���ɼ�
* @param connection ���ݿ�����
* @param stuClass �༶
* @param courseName �γ���
* @return double �༶ĳ��ƽ���ɼ�
*/
double getClassAvgGrade(_ConnectionPtr connection, string stuClass, string courseName);

/*
* ��ȡĳ�༶ĳ�Ƶ���߳ɼ�
* @param connection ���ݿ�����
* @param stuClass �༶
* @param courseName �γ���
* @return double �༶ĳ����߳ɼ�
*/
double getClassMaxGrade(_ConnectionPtr connection, string stuClass, string courseName);

/*
* ��ȡĳ�༶ĳ�Ƶ���ͳɼ�
* @param connection ���ݿ�����
* @param stuClass �༶
* @param courseName �γ���
* @return double �༶ĳ����ͳɼ�
*/
double getClassMinGrade(_ConnectionPtr connection, string stuClass, string courseName);

#endif // !GRADE_DAO_H
