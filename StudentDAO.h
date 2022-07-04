/*
* ѧ�������ݿ�����ӿ�
*/
#ifndef STUDENT_DAO_H
#define STUDENT_DAO_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include<iostream>
#include<vector>
#include"Student.cpp"

/*
* �����ݿ����ѧ��
* @param connection ���ݿ�����
* @param student ����ӵ�ѧ������
*/
void addStudent(_ConnectionPtr connection, Student student);

/*
* ɾ��ѧ��
* @param connection ���ݿ�����
* @param id ѧ��
*/
void deleteStudent(_ConnectionPtr connection, string id);

/*
* �޸�ѧ���༶
* @param connection ���ݿ�����
* @param id ѧ��
* @param stuClass �°༶
*/
void updateStudentClass(_ConnectionPtr connection, string id, string stuClass);

/*
* �޸�ѧ��״̬
* @param connection ���ݿ�����
* @param id ѧ��
* @param status ѧ��״̬���ڶ�����ѧ����ѧ��
*/
void updateStudentStatus(_ConnectionPtr connection, string id, string status);

/*
* ����ѧ�Ż�ȡѧ������
* @param connection ���ݿ�����
* @param id ѧ��
* @return Student* student����ָ��
*/
Student* getStudentById(_ConnectionPtr connection, string id);

/*
* ����������ȡѧ������
* @param connection ���ݿ�����
* @param name ����
* @return vector<Student>* ��Student����ΪԪ�ص�vector����ָ��
*/
std::vector<Student>* getStudentByName(_ConnectionPtr connection, string name);

/*
* ��ȡ����ѧ��
* @param connection ���ݿ�����
* @return vector<Student>* ��Student����ΪԪ�ص�vector����ָ��
*/
std::vector<Student>* getAllStudent(_ConnectionPtr connection);

#endif // !STUDENT_DAO_H