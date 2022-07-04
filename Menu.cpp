#include"Menu.h"

void mainMenu(_ConnectionPtr connection) {
	while (true) {
		try {
			system("cls");
			printf("1.显示所有学生\n");
			printf("2.增加学生\n");
			printf("3.删除学生\n");
			printf("4.修改学生\n");
			printf("5.从文件导入学生信息\n");
			printf("6.导出学生信息到文件\n");
			printf("7.学生成绩管理\n");
			printf("8.课程管理\n");
			printf("9.高级功能\n");
			printf("0.退出\n");

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
			wprintf(L"操作失败！\n");
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
			printf("1.输入学生成绩\n");
			printf("2.获取学生平均成绩\n");
			printf("3.获取学生总成绩\n");
			printf("4.获取班级平均分\n");
			printf("5.获取班级最高分\n");
			printf("6.获取班级最低分\n");
			printf("7.获取班级成绩\n");
			printf("8.二级拓展菜单\n");
			printf("0.返回上一级\n");

			int opt = -1;
			checkOptInput(opt, 0, 8);

			printf("\n");

			string stuId, courseId;
			string stuClass, courseName;
			double grade = -1;
			int size;
			vector<Grade>* v;
			switch (opt) {
			case 1://输入学生成绩
				printf("请输入学号：");
				cin >> stuId;
				printf("请输入课程名：");
				cin >> courseId;
				printf("请输入分数(0-100)：");
				while (!(cin >> grade) || (opt < 0) || (opt > 100)) {
					cout << "输入错误！请重新输入：";
					cin.clear();
					while (cin.get() != '\n');
				}
				addGrade(connection, *new Grade(stuId, courseId, doubleToString(grade)));
				printf("添加成功！\n");
				break;
			case 2://获取学生平均成绩
				printf("请输入学号：");
				cin >> stuId;
				printf("学生平均成绩为：%.2lf\n", getOnesAvgGrade(connection, stuId));
				break;
			case 3://获取学生总成绩
				printf("请输入学号：");
				cin >> stuId;
				printf("学生总成绩为：%.2lf\n", getOnesAllGrade(connection, stuId));
				break;
			case 4://获取班级平均分
				printf("请输入班级：");
				cin >> stuClass;
				printf("请输入课程名：");
				cin >> courseName;
				cout << stuClass << " 班级 " << courseName << " 课程的平均分为：" << getClassAvgGrade(connection, stuClass, courseName) << "\n";
				break;
			case 5://获取班级最高分
				printf("请输入班级：");
				cin >> stuClass;
				printf("请输入课程名：");
				cin >> courseName;
				cout << stuClass << " 班级 " << courseName << " 课程的最高分为：" << getClassMaxGrade(connection, stuClass, courseName) << "\n";
				break;
			case 6://获取班级最低分
				printf("请输入班级：");
				cin >> stuClass;
				printf("请输入课程名：");
				cin >> courseName;
				cout << stuClass << " 班级 " << courseName << " 课程的最低分为：" << getClassMinGrade(connection, stuClass, courseName) << "\n";
				break;
			case 7://获取班级成绩
				printf("请输入班级：");
				cin >> stuClass;
				v = getGradeByStuClass(connection, stuClass);
				if (v == NULL) {
					printf("该班级不存在！\n");
					break;
				}
				size = v->size();
				cout << "学号\t" << "课程名\t" << "成绩\n";
				for (int i = 0; i < size; i++) {
					cout << (*v)[i].toString() << "\n";
				}
				break;
			case 8://二级拓展菜单
				studentGradeExternMenu(connection);
				break;
			default://返回上一级
				return;
			}
			system("pause");
		}
		catch (_com_error& err) {
			wprintf(L"操作失败！\n");
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
			printf("1.删除某学生某科成绩\n");
			printf("2.删除某学生成绩\n");
			printf("3.删除某科成绩\n");
			printf("4.更改某学生某科成绩\n");
			printf("5.查询某学生某科成绩\n");
			printf("6.查询某学生成绩\n");
			printf("7.查询某科成绩\n");
			printf("8.查询所有成绩\n");
			printf("0.返回上一级\n");

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
			case 1://删除某学生某科成绩
				printf("请输入学号：");
				cin >> stuId;
				printf("请输入课程名：");
				cin >> courseName;
				course = getCourseByName(connection, courseName);
				if (course == NULL) {
					printf("该课程不存在！\n");
					break;
				}
				deleteOnesGrade(connection, stuId, course->getId());
				printf("删除成功！\n");
				break;
			case 2://删除某学生成绩
				printf("请输入学号：");
				cin >> stuId;
				deleteGradeByStuId(connection, stuId);
				printf("删除成功！\n");
				break;
			case 3://删除某科成绩
				printf("请输入课程名：");
				cin >> courseName;
				course = getCourseByName(connection, courseName);
				if (course == NULL) {
					printf("该课程不存在！\n");
					break;
				}
				deleteGradeByCourseId(connection, course->getId());
				printf("删除成功！\n");
				break;
			case 4://更改某学生某科成绩
				printf("请输入学号：");
				cin >> stuId;
				printf("请输入课程名：");
				cin >> courseName;
				course = getCourseByName(connection, courseName);
				if (course == NULL) {
					printf("该课程不存在！\n");
					break;
				}
				printf("请输入新分数(0-100)：");
				while (!(cin >> grade) || (opt < 0) || (opt > 100)) {
					cout << "输入错误！请重新输入：";
					cin.clear();
					while (cin.get() != '\n');
				}
				updateOnesGrade(connection, stuId, course->getId(), doubleToString(grade));
				printf("更改成功！\n");
				break;
			case 5://查询某学生某科成绩
				printf("请输入学号：");
				cin >> stuId;
				printf("请输入课程名：");
				cin >> courseName;
				course = getCourseByName(connection, courseName);
				if (course == NULL) {
					printf("该课程不存在！\n");
					break;
				}
				gra = getOnesGrade(connection, stuId, course->getId());
				if (gra == NULL) {
					printf("该条记录不存在！\n");
					break;
				}
				cout << "学号\t" << "课程名\t" << "成绩\n";
				cout << (*gra).toString() << "\n";
				break;
			case 6://查询某学生成绩
				printf("请输入学号：");
				cin >> stuId;
				v = getGradeByStuId(connection, stuId);
				if (v == NULL) {
					printf("该学生不存在！\n");
					break;
				}
				size = v->size();
				cout << "学号\t" << "课程名\t" << "成绩\n";
				for (int i = 0; i < size; i++) {
					cout << (*v)[i].toString() << "\n";
				}
				break;
			case 7://查询某科成绩
				printf("请输入课程名：");
				cin >> courseName;
				course = getCourseByName(connection, courseName);
				if (course == NULL) {
					printf("该课程不存在！\n");
					break;
				}
				v = getGradeByCourseId(connection, course->getId());
				if (v == NULL) {
					printf("该课程不存在对应成绩！\n");
					break;
				}
				size = v->size();
				cout << "学号\t" << "课程名\t" << "成绩\n";
				for (int i = 0; i < size; i++) {
					cout << (*v)[i].toString() << "\n";
				}
				break;
			case 8://查询所有成绩
				v = getAllGrade(connection);
				if (v == NULL) {
					printf("无成绩记录！\n");
					break;
				}
				size = v->size();
				cout << "学号\t" << "课程名\t" << "成绩\n";
				for (int i = 0; i < size; i++) {
					cout << (*v)[i].toString() << "\n";
				}
				break;
			default://返回上一级
				return;
			}
			system("pause");
		}
		catch (_com_error& err) {
			wprintf(L"操作失败！\n");
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
			printf("1.添加课程\n");
			printf("2.删除课程\n");
			printf("3.更改课程\n");
			printf("4.查询所有课程\n");
			printf("0.返回上一级\n");
			int opt = -1;
			checkOptInput(opt, 0, 4);

			printf("\n");

			int size;
			string courseId, courseName;
			vector<Course>* v;
			switch (opt) {
			case 1://添加课程
				printf("请输入课程号：");
				cin >> courseId;
				printf("请输入课程名：");
				cin >> courseName;
				addCourse(connection, *new Course(courseId, courseName));
				printf("添加成功！\n");
				break;
			case 2://删除课程
				printf("请输入课程号：");
				cin >> courseId;
				deleteCourse(connection, courseId);
				printf("删除成功！\n");
				break;
			case 3://更改课程
				printf("请输入课程号：");
				cin >> courseId;
				printf("请输入课程名：");
				cin >> courseName;
				updateCourseName(connection, courseId, courseName);
				printf("更新成功！\n");
				break;
			case 4://查询所有课程
				v = getAllCourse(connection);
				if (v == NULL) {
					printf("不存在课程记录！\n");
					break;
				}
				size = v->size();
				cout << "课程号\t" << "课程名\n";
				for (int i = 0; i < size; i++) {
					cout << (*v)[i].toString() << "\n";
				}
				break;
			default://返回上一级
				return;
			}
			system("pause");
		}
		catch (_com_error& err) {
			wprintf(L"操作失败！\n");
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
			//获取sql命令及种类
			getline(cin, sql);
			while (sql == "" || sql[sql.size() - 1] != ';') {
				wprintf(L"   >");
				string tmp;
				getline(cin, tmp);
				sql += " " + tmp;
			}
			string comType = "";
			getSqlType(sql, comType);
			//执行sql命令
			if (comType == "select") {//查询
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
		printf("学生信息为空！\n");
		return;
	}

	int size = vs->size();
	printf("学号\t姓名\t性别\t班级\t状态\n");
	for (int i = 0; i < size; i++) {
		cout << (*vs)[i].toString() << "\n";
	}
}

void insertStudent(_ConnectionPtr connection) {
	Student *stu = new Student();
	
	string str;
	printf("请输入学号：");
	cin >> str;
	stu->setId(str);
	printf("请输入姓名：");
	cin >> str;
	stu->setName(str);
	printf("请输入性别：");
	cin >> str;
	stu->setSex(str);
	printf("请输入班级：");
	cin >> str;
	stu->setStuClass(str);
	printf("请输入学生状态(在读、休学、退学)：");
	cin >> str;
	stu->setStatus(str);

	addStudent(connection, *stu);
	printf("添加成功！\n");
}

void deleteStudent(_ConnectionPtr connection) {
	string id;
	printf("请输入待删除学生的学号：");
	cin >> id;
	Student *stu = getStudentById(connection,id);
	if (stu == NULL) {
		printf("该学生不存在！\n");
		return;
	}
	deleteStudent(connection, id);
	printf("删除成功！\n");
}

void changeStudent(_ConnectionPtr connection) {
	string id;
	printf("请输入待修改学生的学号：");
	cin >> id;
	Student* stu = getStudentById(connection, id);
	if (stu == NULL) {
		printf("该学生不存在！\n");
		return;
	}

	printf("请选择修改 班级(0) / 学生状态(1)：");
	int opt = -1;
	checkOptInput(opt, 0, 1);

	string input;
	switch (opt) {
		case 0:
			printf("\n请输入新班级：");
			cin >> input;
			updateStudentClass(connection,id,input);
			break;
		default:
			printf("\n请输入新状态：");
			cin >> input;
			updateStudentStatus(connection,id, input);
			break;
	}
}

void exportData(_ConnectionPtr connection) {
	while (true) {
		try {
			system("cls");
			printf("1.导出学生信息\n");
			printf("2.导出课程信息\n");
			printf("3.导出成绩信息\n");
			printf("4.导出所有信息\n");
			printf("0.返回上一级\n");
			int opt = -1;
			checkOptInput(opt, 0, 4);

			printf("\n");

			switch (opt) {
			case 1://导出学生信息
				exportStudentData(connection);
				break;
			case 2://导出课程信息
				exportCourseData(connection);
				break;
			case 3://导出成绩信息
				exportGradeData(connection);
				break;
			case 4://导出所有信息
				exportAllData(connection);
				break;
			default://返回上一级
				return;
			}
			system("pause");
		}
		catch (_com_error& err) {
			wprintf(L"操作失败！\n");
			wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
			wprintf(L"Description = %s\n", (wchar_t*)err.Description());
			system("pause");
		}
	}
}

void exportStudentData(_ConnectionPtr connection) {
	ofstream outFile("student.txt", ios::out);
	if (!outFile.is_open()) {
		printf("导出student.txt文件失败！\n");
		return;
	}

	int size;
	vector<Student>* vs;
	vs = getAllStudent(connection);
	if (vs == NULL) {
		printf("学生信息为空！\n");
		outFile.close();
		return;
	}
	outFile << "学号\t姓名\t性别\t班级\t状态\n";
	size = vs->size();
	for (int i = 0; i < size; i++) {
		outFile << (*vs)[i].toString() << "\n";
	}
	printf("成功导出student.txt文件!\n");
	outFile.close();
}

void exportCourseData(_ConnectionPtr connection) {
	ofstream outFile("course.txt", ios::out);
	if (!outFile.is_open()) {
		printf("导出course.txt文件失败！\n");
		return;
	}

	int size;
	vector<Course>* vc;
	vc = getAllCourse(connection);
	if (vc == NULL) {
		printf("课程信息为空！\n");
		outFile.close();
		return;
	}
	outFile << "课程号\t课程名\n";
	size = vc->size();
	for (int i = 0; i < size; i++) {
		outFile << (*vc)[i].toString() << "\n";
	}
	printf("成功导出course.txt文件!\n");
	outFile.close();
}

void exportGradeData(_ConnectionPtr connection) {
	ofstream outFile("grade.txt", ios::out);
	if (!outFile.is_open()) {
		printf("导出grade.txt文件失败！\n");
		return;
	}

	int size;
	vector<Grade>* vg;
	vg = getAllGrade(connection);
	if (vg == NULL) {
		printf("成绩信息为空！\n");
		outFile.close();
		return;
	}
	outFile << "学号\t课程号\t成绩\n";
	size = vg->size();
	for (int i = 0; i < size; i++) {
		outFile << (*vg)[i].toString() << "\n";
	}
	printf("成功导出grade.txt文件!\n");
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
			printf("1.导入学生信息\n");
			printf("2.导入课程信息\n");
			printf("3.导入成绩信息\n");
			printf("4.导入所有信息\n");
			printf("0.返回上一级\n");
			int opt = -1;
			checkOptInput(opt, 0, 4);

			printf("\n");

			switch (opt) {
			case 1://导入学生信息
				importStudentData(connection);
				break;
			case 2://导入课程信息
				importCourseData(connection);
				break;
			case 3://导入成绩信息
				importGradeData(connection);
				break;
			case 4://导入所有信息
				importAllData(connection);
				break;
			default://返回上一级
				return;
			}
			system("pause");
		}
		catch (_com_error& err) {
			wprintf(L"操作失败！\n");
			wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
			wprintf(L"Description = %s\n", (wchar_t*)err.Description());
			system("pause");
		}
	}
}

void importStudentData(_ConnectionPtr connection) {
	ifstream inFile("student.txt", ios::in);
	if (!inFile.is_open()) {
		printf("读取student.txt文件失败！\n");
		return;
	}

	string title[5];
	inFile >> title[0] >> title[1] >> title[2] >> title[3] >> title[4];
	if (!(title[0] == "学号" && title[1] == "姓名" && title[2] == "性别" && title[3] == "班级" && title[4] == "状态")) {
		printf("文件格式异常，读取失败！\n");
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
	printf("成功导入student.txt文件!\n");
	inFile.close();
}

void importCourseData(_ConnectionPtr connection) {
	ifstream inFile("course.txt", ios::in);
	if (!inFile.is_open()) {
		printf("读取course.txt文件失败！\n");
		return;
	}

	string title[2];
	inFile >> title[0] >> title[1];
	if (!(title[0] == "课程号" && title[1] == "课程名")) {
		printf("文件格式异常，读取失败！\n");
		return;
	}

	Course* course = new Course();
	while (!inFile.eof()) {
		inFile >> title[0] >> title[1];
		course->setId(title[0]);
		course->setName(title[1]);
		addCourse(connection, *course);
	}
	printf("成功导入course.txt文件!\n");
	inFile.close();
}

void importGradeData(_ConnectionPtr connection) {
	ifstream inFile("grade.txt", ios::in);
	if (!inFile.is_open()) {
		printf("读取grade.txt文件失败！\n");
		return;
	}

	string title[3];
	inFile >> title[0] >> title[1] >> title[2];
	if (!(title[0] == "学号" && title[1] == "课程号" && title[2] == "成绩")) {
		printf("文件格式异常，读取失败！\n");
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
	printf("成功导入grade.txt文件!\n");
	inFile.close();
}

void importAllData(_ConnectionPtr connection) {
	importStudentData(connection);
	importCourseData(connection);
	importGradeData(connection);
}