#include"Menu.h"

void mainMenu(_ConnectionPtr connection) {
	while (true) {
		try {
			system("cls");
			printf("1.��ʾ����ѧ��\n");
			printf("2.����ѧ��\n");
			printf("3.ɾ��ѧ��\n");
			printf("4.�޸�ѧ��\n");
			printf("5.���ļ�����ѧ����Ϣ\n");
			printf("6.����ѧ����Ϣ���ļ�\n");
			printf("7.ѧ���ɼ�����\n");
			printf("8.�γ̹���\n");
			printf("9.�߼�����\n");
			printf("0.�˳�\n");

			int opt = -1;
			checkOptInput(opt, 0, 9);

			switch (opt) {
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
			case 9:
				advancedFunction(connection);
				break;
			default:
				exit(EXIT_SUCCESS);
			}
			printf("\n");
			system("pause");
		}
		catch (_com_error& err) {
			wprintf(L"����ʧ�ܣ�\n");
			wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
			wprintf(L"Description = %s\n", (wchar_t*)err.Description());
			system("pause");
		}
	}
}

void studentGradeMenu(_ConnectionPtr connection) {
	while (true) {
		try {
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
			vector<Grade>* v;
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
				cout << stuClass << " �༶ " << courseName << " �γ̵�ƽ����Ϊ��" << getClassAvgGrade(connection, stuClass, courseName) << "\n";
				break;
			case 5://��ȡ�༶��߷�
				printf("������༶��");
				cin >> stuClass;
				printf("������γ�����");
				cin >> courseName;
				cout << stuClass << " �༶ " << courseName << " �γ̵���߷�Ϊ��" << getClassMaxGrade(connection, stuClass, courseName) << "\n";
				break;
			case 6://��ȡ�༶��ͷ�
				printf("������༶��");
				cin >> stuClass;
				printf("������γ�����");
				cin >> courseName;
				cout << stuClass << " �༶ " << courseName << " �γ̵���ͷ�Ϊ��" << getClassMinGrade(connection, stuClass, courseName) << "\n";
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
					cout << (*v)[i].toString() << "\n";
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
		catch (_com_error& err) {
			wprintf(L"����ʧ�ܣ�\n");
			wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
			wprintf(L"Description = %s\n", (wchar_t*)err.Description());
			system("pause");
		}
	}
}

void studentGradeExternMenu(_ConnectionPtr connection) {
	while (true) {
		try {
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
			vector<Grade>* v;
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
				cout << (*gra).toString() << "\n";
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
					cout << (*v)[i].toString() << "\n";
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
					cout << (*v)[i].toString() << "\n";
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
					cout << (*v)[i].toString() << "\n";
				}
				break;
			default://������һ��
				return;
			}
			system("pause");
		}
		catch (_com_error& err) {
			wprintf(L"����ʧ�ܣ�\n");
			wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
			wprintf(L"Description = %s\n", (wchar_t*)err.Description());
			system("pause");
		}
	}
}

void courseMenu(_ConnectionPtr connection) {
	while (true) {
		try {
			system("cls");
			printf("1.��ӿγ�\n");
			printf("2.ɾ���γ�\n");
			printf("3.���Ŀγ�\n");
			printf("4.��ѯ���пγ�\n");
			printf("0.������һ��\n");
			int opt = -1;
			checkOptInput(opt, 0, 4);

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
				addCourse(connection, *new Course(courseId, courseName));
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
				updateCourseName(connection, courseId, courseName);
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
					cout << (*v)[i].toString() << "\n";
				}
				break;
			default://������һ��
				return;
			}
			system("pause");
		}
		catch (_com_error& err) {
			wprintf(L"����ʧ�ܣ�\n");
			wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
			wprintf(L"Description = %s\n", (wchar_t*)err.Description());
			system("pause");
		}
	}
}

void advancedFunction(_ConnectionPtr connection) {
	system("cls");
	_RecordsetPtr record(_uuidof(Recordset));
	string sql;

	cin.clear();
	while (cin.get() != '\n');
	while (true) {
		try {
			wprintf(L"sql>");
			//��ȡsql�������
			getline(cin, sql);
			while (sql == "" || sql[sql.size() - 1] != ';') {
				wprintf(L"   >");
				string tmp;
				getline(cin, tmp);
				sql += " " + tmp;
			}
			string comType = "";
			getSqlType(sql, comType);
			//ִ��sql����
			if (comType == "select") {//��ѯ
				record = connection->Execute(sql.c_str(), NULL, (long)0);
				for (long i = 0; i < record->Fields->Count; i++)
					wprintf(L"%s\t", (wchar_t*)record->Fields->GetItem(i)->Name);
				printf("\n");
				wprintf(L"%s", (wchar_t*)record->GetString(adClipString, long(-1), "\t", "\n", "Null"));
				//showRecordInfo(record);
			}else if (comType == "exit" || comType == "exit;") {
				system("pause");
				break;
			}else {
				connection->Execute(sql.c_str(), NULL, (long)0);
			}
			printf("\n");
		}
		catch (_com_error& err) {
			wprintf(L"\nThe application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
			wprintf(L"Description = %s\n\n", (wchar_t*)err.Description());
		}
	}
}



void showAllStudent(_ConnectionPtr connection) {
	vector<Student>* vs = getAllStudent(connection);
	if (vs == NULL) {
		printf("ѧ����ϢΪ�գ�\n");
		return;
	}

	int size = vs->size();
	printf("ѧ��\t����\t�Ա�\t�༶\t״̬\n");
	for (int i = 0; i < size; i++) {
		cout << (*vs)[i].toString() << "\n";
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
	while (true) {
		try {
			system("cls");
			printf("1.����ѧ����Ϣ\n");
			printf("2.�����γ���Ϣ\n");
			printf("3.�����ɼ���Ϣ\n");
			printf("4.����������Ϣ\n");
			printf("0.������һ��\n");
			int opt = -1;
			checkOptInput(opt, 0, 4);

			printf("\n");

			switch (opt) {
			case 1://����ѧ����Ϣ
				exportStudentData(connection);
				break;
			case 2://�����γ���Ϣ
				exportCourseData(connection);
				break;
			case 3://�����ɼ���Ϣ
				exportGradeData(connection);
				break;
			case 4://����������Ϣ
				exportAllData(connection);
				break;
			default://������һ��
				return;
			}
			system("pause");
		}
		catch (_com_error& err) {
			wprintf(L"����ʧ�ܣ�\n");
			wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
			wprintf(L"Description = %s\n", (wchar_t*)err.Description());
			system("pause");
		}
	}
}

void exportStudentData(_ConnectionPtr connection) {
	ofstream outFile("student.txt", ios::out);
	if (!outFile.is_open()) {
		printf("����student.txt�ļ�ʧ�ܣ�\n");
		return;
	}

	int size;
	vector<Student>* vs;
	vs = getAllStudent(connection);
	if (vs == NULL) {
		printf("ѧ����ϢΪ�գ�\n");
		outFile.close();
		return;
	}
	outFile << "ѧ��\t����\t�Ա�\t�༶\t״̬\n";
	size = vs->size();
	for (int i = 0; i < size; i++) {
		outFile << (*vs)[i].toString() << "\n";
	}
	printf("�ɹ�����student.txt�ļ�!\n");
	outFile.close();
}

void exportCourseData(_ConnectionPtr connection) {
	ofstream outFile("course.txt", ios::out);
	if (!outFile.is_open()) {
		printf("����course.txt�ļ�ʧ�ܣ�\n");
		return;
	}

	int size;
	vector<Course>* vc;
	vc = getAllCourse(connection);
	if (vc == NULL) {
		printf("�γ���ϢΪ�գ�\n");
		outFile.close();
		return;
	}
	outFile << "�γ̺�\t�γ���\n";
	size = vc->size();
	for (int i = 0; i < size; i++) {
		outFile << (*vc)[i].toString() << "\n";
	}
	printf("�ɹ�����course.txt�ļ�!\n");
	outFile.close();
}

void exportGradeData(_ConnectionPtr connection) {
	ofstream outFile("grade.txt", ios::out);
	if (!outFile.is_open()) {
		printf("����grade.txt�ļ�ʧ�ܣ�\n");
		return;
	}

	int size;
	vector<Grade>* vg;
	vg = getAllGrade(connection);
	if (vg == NULL) {
		printf("�ɼ���ϢΪ�գ�\n");
		outFile.close();
		return;
	}
	outFile << "ѧ��\t�γ̺�\t�ɼ�\n";
	size = vg->size();
	for (int i = 0; i < size; i++) {
		outFile << (*vg)[i].toString() << "\n";
	}
	printf("�ɹ�����grade.txt�ļ�!\n");
	outFile.close();
}

void exportAllData(_ConnectionPtr connection) {
	exportStudentData(connection);
	exportCourseData(connection);
	exportGradeData(connection);
}



void importData(_ConnectionPtr connection) {
	while (true) {
		try {
			system("cls");
			printf("1.����ѧ����Ϣ\n");
			printf("2.����γ���Ϣ\n");
			printf("3.����ɼ���Ϣ\n");
			printf("4.����������Ϣ\n");
			printf("0.������һ��\n");
			int opt = -1;
			checkOptInput(opt, 0, 4);

			printf("\n");

			switch (opt) {
			case 1://����ѧ����Ϣ
				importStudentData(connection);
				break;
			case 2://����γ���Ϣ
				importCourseData(connection);
				break;
			case 3://����ɼ���Ϣ
				importGradeData(connection);
				break;
			case 4://����������Ϣ
				importAllData(connection);
				break;
			default://������һ��
				return;
			}
			system("pause");
		}
		catch (_com_error& err) {
			wprintf(L"����ʧ�ܣ�\n");
			wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
			wprintf(L"Description = %s\n", (wchar_t*)err.Description());
			system("pause");
		}
	}
}

void importStudentData(_ConnectionPtr connection) {
	ifstream inFile("student.txt", ios::in);
	if (!inFile.is_open()) {
		printf("��ȡstudent.txt�ļ�ʧ�ܣ�\n");
		return;
	}

	string title[5];
	inFile >> title[0] >> title[1] >> title[2] >> title[3] >> title[4];
	if (!(title[0] == "ѧ��" && title[1] == "����" && title[2] == "�Ա�" && title[3] == "�༶" && title[4] == "״̬")) {
		printf("�ļ���ʽ�쳣����ȡʧ�ܣ�\n");
		return;
	}

	Student* student = new Student();
	while (!inFile.eof()) {
		inFile >> title[0] >> title[1] >> title[2] >> title[3] >> title[4];
		student->setId(title[0]);
		student->setName(title[1]);
		student->setSex(title[2]);
		student->setStuClass(title[3]);
		student->setStatus(title[4]);
		addStudent(connection, *student);
	}
	printf("�ɹ�����student.txt�ļ�!\n");
	inFile.close();
}

void importCourseData(_ConnectionPtr connection) {
	ifstream inFile("course.txt", ios::in);
	if (!inFile.is_open()) {
		printf("��ȡcourse.txt�ļ�ʧ�ܣ�\n");
		return;
	}

	string title[2];
	inFile >> title[0] >> title[1];
	if (!(title[0] == "�γ̺�" && title[1] == "�γ���")) {
		printf("�ļ���ʽ�쳣����ȡʧ�ܣ�\n");
		return;
	}

	Course* course = new Course();
	while (!inFile.eof()) {
		inFile >> title[0] >> title[1];
		course->setId(title[0]);
		course->setName(title[1]);
		addCourse(connection, *course);
	}
	printf("�ɹ�����course.txt�ļ�!\n");
	inFile.close();
}

void importGradeData(_ConnectionPtr connection) {
	ifstream inFile("grade.txt", ios::in);
	if (!inFile.is_open()) {
		printf("��ȡgrade.txt�ļ�ʧ�ܣ�\n");
		return;
	}

	string title[3];
	inFile >> title[0] >> title[1] >> title[2];
	if (!(title[0] == "ѧ��" && title[1] == "�γ̺�" && title[2] == "�ɼ�")) {
		printf("�ļ���ʽ�쳣����ȡʧ�ܣ�\n");
		return;
	}

	Grade* grade = new Grade();
	while (!inFile.eof()) {
		inFile >> title[0] >> title[1] >> title[2];
		grade->setStuId(title[0]);
		grade->setCourseId(title[1]);
		grade->setGrade(title[2]);
		addGrade(connection, *grade);
	}
	printf("�ɹ�����grade.txt�ļ�!\n");
	inFile.close();
}

void importAllData(_ConnectionPtr connection) {
	importStudentData(connection);
	importCourseData(connection);
	importGradeData(connection);
}