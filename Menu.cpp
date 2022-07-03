#include<iostream>
#include"Menu.h"
#include"MenuUtils.h"
#include"StudentDAO.h"
#include"GradeDAO.h"
#include"CourseDAO.h"
using namespace std;

void mainMenu(_ConnectionPtr connection) {
	system("cls");
	printf("1.��ʾ����ѧ��\n");
	printf("2.����ѧ��\n");
	printf("3.ɾ��ѧ��\n");
	printf("4.�޸�ѧ��\n");
	printf("5.���ļ�����ѧ����Ϣ\n");
	printf("6.����ѧ����Ϣ���ļ�\n");
	printf("7.ѧ���ɼ�����\n");
	printf("8.�γ̹���\n");
	printf("0.�˳�\n");

	int opt = -1;
	checkOptInput(opt, 0, 8);

	switch (opt){
		case 1:
			showAllStudent(connection);
			break;
		case 2:
			insertStudent(connection);
			break;
		case 3:
			deleteStudent(connection);
			break;
		case 4:
			changeStudent(connection);
			break;
		case 5:
			importData(connection);
			break;
		case 6:
			exportData(connection);
			break;
		case 7:
			studentGradeMenu(connection);
			break;
		case 8:
			courseMenu(connection);
			break;
		default:
			exit(EXIT_SUCCESS);
	}
	printf("\n");
}

void studentGradeMenu(_ConnectionPtr connection) {
	while (true) {
		system("cls");
		printf("1.����ѧ���ɼ�\n");
		printf("2.��ȡѧ��ƽ���ɼ�\n");
		printf("3.��ȡѧ���ܳɼ�\n");
		printf("4.��ȡ�༶ƽ����\n");
		printf("5.��ȡ�༶��߷�\n");
		printf("6.��ȡ�༶��ͷ�\n");
		printf("7.��ȡ�༶�ɼ�\n");
		printf("8.������չ�˵�\n");
		printf("0.������һ��\n");

		int opt = -1;
		checkOptInput(opt, 0, 8);

		printf("\n");

		string stuId, courseId;
		string stuClass, courseName;
		double grade = -1;
		int size;
		vector<Grade> *v;
		switch (opt) {
			case 1://����ѧ���ɼ�
				printf("������ѧ�ţ�");
				cin >> stuId;
				printf("������γ�����");
				cin >> courseId;
				printf("���������(0-100)��");
				while (!(cin >> grade) || (opt < 0) || (opt > 100)) {
					cout << "����������������룺";
					cin.clear();
					while (cin.get() != '\n');
				}
				addGrade(connection, *new Grade(stuId, courseId, doubleToString(grade)));
				printf("��ӳɹ���\n");
				break;
			case 2://��ȡѧ��ƽ���ɼ�
				printf("������ѧ�ţ�");
				cin >> stuId;
				printf("ѧ��ƽ���ɼ�Ϊ��%.2lf\n", getOnesAvgGrade(connection, stuId));
				break;
			case 3://��ȡѧ���ܳɼ�
				printf("������ѧ�ţ�");
				cin >> stuId;
				printf("ѧ���ܳɼ�Ϊ��%.2lf\n", getOnesAllGrade(connection, stuId));
				break;
			case 4://��ȡ�༶ƽ����
				printf("������༶��");
				cin >> stuClass;
				printf("������γ�����");
				cin >> courseName;
				cout << stuClass << "�༶" << courseName << "�γ̵�ƽ����Ϊ��" << getClassAvgGrade(connection, stuClass, courseName) << "\n";
				break;
			case 5://��ȡ�༶��߷�
				printf("������༶��");
				cin >> stuClass;
				printf("������γ�����");
				cin >> courseName;
				cout << stuClass << "�༶" << courseName << "�γ̵���߷�Ϊ��" << getClassMaxGrade(connection, stuClass, courseName) << "\n";
				break;
			case 6://��ȡ�༶��ͷ�
				printf("������༶��");
				cin >> stuClass;
				printf("������γ�����");
				cin >> courseName;
				cout << stuClass << "�༶" << courseName << "�γ̵���ͷ�Ϊ��" << getClassMinGrade(connection, stuClass, courseName) << "\n";
				break;
			case 7://��ȡ�༶�ɼ�
				printf("������༶��");
				cin >> stuClass;
				v = getGradeByStuClass(connection, stuClass);
				if (v == NULL) {
					printf("�ð༶�����ڣ�\n");
					break;
				}
				size = v->size();
				cout << "ѧ��\t" << "�γ���\t" << "�ɼ�\n";
				for (int i = 0; i < size; i++) {
					cout << (*v)[i].getStuId() << "\t" << getCourseById(connection, (*v)[i].getCourseId())->getName() << "\t" << (*v)[i].getGradeStr() << "\n";
				}
				break;
			case 8://������չ�˵�
				studentGradeExternMenu(connection);
				break;
			default://������һ��
				return;
		}
		system("pause");
	}
}

void studentGradeExternMenu(_ConnectionPtr connection) {
	while (true) {
		system("cls");
		printf("1.ɾ��ĳѧ��ĳ�Ƴɼ�\n");
		printf("2.ɾ��ĳѧ���ɼ�\n");
		printf("3.ɾ��ĳ�Ƴɼ�\n");
		printf("4.����ĳѧ��ĳ�Ƴɼ�\n");
		printf("5.��ѯĳѧ��ĳ�Ƴɼ�\n");
		printf("6.��ѯĳѧ���ɼ�\n");
		printf("7.��ѯĳ�Ƴɼ�\n");
		printf("8.��ѯ���гɼ�\n");
		printf("0.������һ��\n");

		int opt = -1;
		checkOptInput(opt, 0, 8);

		printf("\n");

		string stuId, courseId;
		string stuClass, courseName;
		double grade = -1;
		int size;
		vector<Grade> *v;
		Grade* gra;
		Course* course;
		switch (opt) {
			case 1://ɾ��ĳѧ��ĳ�Ƴɼ�
				printf("������ѧ�ţ�");
				cin >> stuId;
				printf("������γ�����");
				cin >> courseName;
				course = getCourseByName(connection, courseName);
				if (course == NULL) {
					printf("�ÿγ̲����ڣ�\n");
					break;
				}
				deleteOnesGrade(connection, stuId, course->getId());
				printf("ɾ���ɹ���\n");
				break;
			case 2://ɾ��ĳѧ���ɼ�
				printf("������ѧ�ţ�");
				cin >> stuId;
				deleteGradeByStuId(connection, stuId);
				printf("ɾ���ɹ���\n");
				break;
			case 3://ɾ��ĳ�Ƴɼ�
				printf("������γ�����");
				cin >> courseName;
				course = getCourseByName(connection, courseName);
				if (course == NULL) {
					printf("�ÿγ̲����ڣ�\n");
					break;
				}
				deleteGradeByCourseId(connection, course->getId());
				printf("ɾ���ɹ���\n");
				break;
			case 4://����ĳѧ��ĳ�Ƴɼ�
				printf("������ѧ�ţ�");
				cin >> stuId;
				printf("������γ�����");
				cin >> courseName;
				course = getCourseByName(connection, courseName);
				if (course == NULL) {
					printf("�ÿγ̲����ڣ�\n");
					break;
				}
				printf("�������·���(0-100)��");
				while (!(cin >> grade) || (opt < 0) || (opt > 100)) {
					cout << "����������������룺";
					cin.clear();
					while (cin.get() != '\n');
				}
				updateOnesGrade(connection, stuId, course->getId(), doubleToString(grade));
				printf("���ĳɹ���\n");
				break;
			case 5://��ѯĳѧ��ĳ�Ƴɼ�
				printf("������ѧ�ţ�");
				cin >> stuId;
				printf("������γ�����");
				cin >> courseName;
				course = getCourseByName(connection, courseName);
				if (course == NULL) {
					printf("�ÿγ̲����ڣ�\n");
					break;
				}
				gra = getOnesGrade(connection, stuId, course->getId());
				if (gra == NULL) {
					printf("������¼�����ڣ�\n");
					break;
				}
				cout << "ѧ��\t" << "�γ���\t" << "�ɼ�\n";
				cout << (*gra).getStuId() << "\t" << getCourseById(connection, (*gra).getCourseId())->getName() << "\t" << (*gra).getGradeStr() << "\n";
				break;
			case 6://��ѯĳѧ���ɼ�
				printf("������ѧ�ţ�");
				cin >> stuId;
				v = getGradeByStuId(connection, stuId);
				if (v == NULL) {
					printf("��ѧ�������ڣ�\n");
					break;
				}
				size = v->size();
				cout << "ѧ��\t" << "�γ���\t" << "�ɼ�\n";
				for (int i = 0; i < size; i++) {
					cout << (*v)[i].getStuId() << "\t" << getCourseById(connection, (*v)[i].getCourseId())->getName() << "\t" << (*v)[i].getGradeStr() << "\n";
				}
				break;
			case 7://��ѯĳ�Ƴɼ�
				printf("������γ�����");
				cin >> courseName;
				course = getCourseByName(connection, courseName);
				if (course == NULL) {
					printf("�ÿγ̲����ڣ�\n");
					break;
				}
				v = getGradeByCourseId(connection, course->getId());
				if (v == NULL) {
					printf("�ÿγ̲����ڶ�Ӧ�ɼ���\n");
					break;
				}
				size = v->size();
				cout << "ѧ��\t" << "�γ���\t" << "�ɼ�\n";
				for (int i = 0; i < size; i++) {
					cout << (*v)[i].getStuId() << "\t" << getCourseById(connection, (*v)[i].getCourseId())->getName() << "\t" << (*v)[i].getGradeStr() << "\n";
				}
				break;
			case 8://��ѯ���гɼ�
				v = getAllGrade(connection);
				if (v == NULL) {
					printf("�޳ɼ���¼��\n");
					break;
				}
				size = v->size();
				cout << "ѧ��\t" << "�γ���\t" << "�ɼ�\n";
				for (int i = 0; i < size; i++) {
					cout << (*v)[i].getStuId() << "\t" << getCourseById(connection, (*v)[i].getCourseId())->getName() << "\t" << (*v)[i].getGradeStr() << "\n";
				}
				break;
			default://������һ��
				return;
		}
		system("pause");
	}
}

void courseMenu(_ConnectionPtr connection) {
	while (true) {
		system("cls");
		printf("1.��ӿγ�\n");
		printf("2.ɾ���γ�\n");
		printf("3.���Ŀγ�\n");
		printf("4.��ѯ���пγ�\n");
		printf("0.������һ��\n");
		int opt = -1;
		checkOptInput(opt, 0, 8);

		printf("\n");

		int size;
		string courseId, courseName;
		vector<Course>* v;
		switch (opt) {
			case 1://��ӿγ�
				printf("������γ̺ţ�");
				cin >> courseId;
				printf("������γ�����");
				cin >> courseName;
				addCourse(connection,*new Course(courseId, courseName));
				printf("��ӳɹ���\n");
				break;
			case 2://ɾ���γ�
				printf("������γ̺ţ�");
				cin >> courseId;
				deleteCourse(connection, courseId);
				printf("ɾ���ɹ���\n");
				break;
			case 3://���Ŀγ�
				printf("������γ̺ţ�");
				cin >> courseId;
				printf("������γ�����");
				cin >> courseName;
				updateCourseName(connection, courseId,courseName);
				printf("���³ɹ���\n");
				break;
			case 4://��ѯ���пγ�
				v = getAllCourse(connection);
				if (v == NULL) {
					printf("�����ڿγ̼�¼��\n");
					break;
				}
				size = v->size();
				cout << "�γ̺�\t" << "�γ���\n";
				for (int i = 0; i < size; i++) {
					cout << (*v)[i].getId() << "\t" << (*v)[i].getName() << "\n";
				}
				break;
			default://������һ��
				return;
		}
		system("pause");
	}
}

void showAllStudent(_ConnectionPtr connection) {
	vector<Student> vs = *getAllStudent(connection);
	int size = vs.size();
	for (int i = 0; i < size; i++) {
		cout << vs[i].toString() << "\n";
	}
}

void insertStudent(_ConnectionPtr connection) {
	Student *stu = new Student();
	
	string str;
	printf("������ѧ�ţ�");
	cin >> str;
	stu->setId(str);
	printf("������������");
	cin >> str;
	stu->setName(str);
	printf("�������Ա�");
	cin >> str;
	stu->setSex(str);
	printf("������༶��");
	cin >> str;
	stu->setStuClass(str);
	printf("������ѧ��״̬(�ڶ�����ѧ����ѧ)��");
	cin >> str;
	stu->setStatus(str);

	addStudent(connection, *stu);
	printf("��ӳɹ���\n");
}

void deleteStudent(_ConnectionPtr connection) {
	string id;
	printf("�������ɾ��ѧ����ѧ�ţ�");
	cin >> id;
	Student *stu = getStudentById(connection,id);
	if (stu == NULL) {
		printf("��ѧ�������ڣ�\n");
		return;
	}
	deleteStudent(connection, id);
	printf("ɾ���ɹ���\n");
}

void changeStudent(_ConnectionPtr connection) {
	string id;
	printf("��������޸�ѧ����ѧ�ţ�");
	cin >> id;
	Student* stu = getStudentById(connection, id);
	if (stu == NULL) {
		printf("��ѧ�������ڣ�\n");
		return;
	}

	printf("��ѡ���޸� �༶(0) / ѧ��״̬(1)��");
	int opt = -1;
	checkOptInput(opt, 0, 1);

	string input;
	switch (opt) {
		case 0:
			printf("\n�������°༶��");
			cin >> input;
			updateStudentClass(connection,id,input);
			break;
		default:
			printf("\n��������״̬��");
			cin >> input;
			updateStudentStatus(connection,id, input);
			break;
	}
}

void exportData(_ConnectionPtr connection) {

}

void importData(_ConnectionPtr connection) {

}