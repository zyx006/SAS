/*
* 成绩表数据库操作接口实现
*/
#include"GradeDAO.h"

void addGrade(_ConnectionPtr connection, Grade grade) {
	string sql = "insert into grade values(?,?,?)";

	vector<string>* v = new vector<string>();
	v->push_back(grade.getStuId());
	v->push_back(grade.getCourseId());
	v->push_back(grade.getGradeStr());

	executeSql(connection, sql.c_str(), v);
}

void deleteOnesGrade(_ConnectionPtr connection, string stuId, string courseId) {
	string sql = "delete from grade where stuId = ? and courseId = ?";

	vector<string>* v = new vector<string>();
	v->push_back(stuId);
	v->push_back(courseId);

	executeSql(connection, sql.c_str(), v);
}

void deleteGradeByStuId(_ConnectionPtr connection, string stuId) {
	string sql = "delete from grade where stuId = ?";

	vector<string>* v = new vector<string>();
	v->push_back(stuId);

	executeSql(connection, sql.c_str(), v);
}

void deleteGradeByCourseId(_ConnectionPtr connection, string courseId) {
	string sql = "delete from grade where courseId = ?";

	vector<string>* v = new vector<string>();
	v->push_back(courseId);

	executeSql(connection, sql.c_str(), v);
}

void updateOnesGrade(_ConnectionPtr connection, string stuId, string courseId, string grade) {
	string sql = "update grade set grade = ? where stuId = ? and courseId = ?";

	vector<string>* v = new vector<string>();
	v->push_back(grade);
	v->push_back(stuId);
	v->push_back(courseId);

	executeSql(connection, sql.c_str(), v);
}

Grade* getOnesGrade(_ConnectionPtr connection, string stuId,string courseId) {
	string sql = "select * from grade where stuId = ? and courseId = ?";

	vector<string>* v = new vector<string>();
	v->push_back(stuId);
	v->push_back(courseId);

	_RecordsetPtr record = executeSql(connection, sql.c_str(), v);
	if (record->BOF == -1) return NULL;//记录集为空

	Grade* grade = new Grade();
	grade->setStuId((char*)(_bstr_t)record->Fields->GetItem("stuId")->Value);
	grade->setCourseId((char*)(_bstr_t)record->Fields->GetItem("courseId")->Value);
	grade->setGrade((char*)(_bstr_t)record->Fields->GetItem("grade")->Value);
	return grade;
}

std::vector<Grade>* getGradeByStuId(_ConnectionPtr connection, string stuId) {
	string sql = "select * from grade where stuId = ?";

	vector<string>* v = new vector<string>();
	v->push_back(stuId);

	_RecordsetPtr record = executeSql(connection, sql.c_str(), v);
	if (record->BOF == -1) return NULL;//记录集为空

	std::vector<Grade>* vg = new std::vector<Grade>();
	Grade* grade;
	for (; !record->EndOfFile; record->MoveNext()) {
		grade = new Grade();
		grade->setStuId((char*)(_bstr_t)record->Fields->GetItem("stuId")->Value);
		grade->setCourseId((char*)(_bstr_t)record->Fields->GetItem("courseId")->Value);
		grade->setGrade((char*)(_bstr_t)record->Fields->GetItem("grade")->Value);
		vg->push_back(*grade);
	}
	return vg;
}

std::vector<Grade>* getGradeByCourseId(_ConnectionPtr connection, string courseId) {
	string sql = "select * from grade where courseId = ?";

	vector<string>* v = new vector<string>();
	v->push_back(courseId);

	_RecordsetPtr record = executeSql(connection, sql.c_str(), v);
	if (record->BOF == -1) return NULL;//记录集为空

	std::vector<Grade>* vg = new std::vector<Grade>();
	Grade* grade;
	for (; !record->EndOfFile; record->MoveNext()) {
		grade = new Grade();
		grade->setStuId((char*)(_bstr_t)record->Fields->GetItem("stuId")->Value);
		grade->setCourseId((char*)(_bstr_t)record->Fields->GetItem("courseId")->Value);
		grade->setGrade((char*)(_bstr_t)record->Fields->GetItem("grade")->Value);
		vg->push_back(*grade);
	}
	return vg;
}

std::vector<Grade>* getGradeByStuClass(_ConnectionPtr connection, string stuClass) {
	string sql = "select * from grade where stuId in (select id from student where stuClass = ?)";
	
	vector<string>* v = new vector<string>();
	v->push_back(stuClass);

	_RecordsetPtr record = executeSql(connection, sql.c_str(), v);
	if (record->BOF == -1) return NULL;//记录集为空

	std::vector<Grade>* vg = new std::vector<Grade>();
	Grade* grade;
	for (; !record->EndOfFile; record->MoveNext()) {
		grade = new Grade();
		grade->setStuId((char*)(_bstr_t)record->Fields->GetItem("stuId")->Value);
		grade->setCourseId((char*)(_bstr_t)record->Fields->GetItem("courseId")->Value);
		grade->setGrade((char*)(_bstr_t)record->Fields->GetItem("grade")->Value);
		vg->push_back(*grade);
	}
	return vg;
}

std::vector<Grade>* getAllGrade(_ConnectionPtr connection) {
	string sql = "select * from grade";

	_RecordsetPtr record = executeSql(connection, sql.c_str(), NULL);
	if (record->BOF == -1) return NULL;//记录集为空

	std::vector<Grade>* v = new std::vector<Grade>();
	Grade* grade;
	for (; !record->EndOfFile; record->MoveNext()) {
		grade = new Grade();
		grade->setStuId((char*)(_bstr_t)record->Fields->GetItem("stuId")->Value);
		grade->setCourseId((char*)(_bstr_t)record->Fields->GetItem("courseId")->Value);
		grade->setGrade((char*)(_bstr_t)record->Fields->GetItem("grade")->Value);
		v->push_back(*grade);
	}
	return v;
}

double getOnesAvgGrade(_ConnectionPtr connection, string stuId) {
	string sql = "select count(*) cnt,sum(grade) all_grade from grade where stuId = ?";
	
	vector<string>* v = new vector<string>();
	v->push_back(stuId);

	_RecordsetPtr record = executeSql(connection, sql.c_str(), v);
	if (record->BOF == -1) return NULL;//记录集为空

	int cnt = atoi((char*)(_bstr_t)record->Fields->GetItem("cnt")->Value);
	double all_grade = atof((char*)(_bstr_t)record->Fields->GetItem("all_grade")->Value);
	return all_grade / cnt;
}

double getOnesAllGrade(_ConnectionPtr connection, string stuId) {
	string sql = "select sum(grade) all_grade from grade where stuId = ?";
	
	vector<string>* v = new vector<string>();
	v->push_back(stuId);

	_RecordsetPtr record = executeSql(connection, sql.c_str(), v);
	if (record->BOF == -1) return NULL;//记录集为空

	return atof((char*)(_bstr_t)record->Fields->GetItem("all_grade")->Value);
}

double getClassAvgGrade(_ConnectionPtr connection, string stuClass, string courseName) {
	string sql = "select avg(grade) avg_grade from grade where stuId in (select id from student where stuClass = ?) and courseId in (select id from course where name = ?)";
	
	vector<string>* v = new vector<string>();
	v->push_back(stuClass);
	v->push_back(courseName);

	_RecordsetPtr record = executeSql(connection, sql.c_str(), v);
	if (record->BOF == -1) return NULL;//记录集为空

	return atof((char*)(_bstr_t)record->Fields->GetItem("avg_grade")->Value);
}

double getClassMaxGrade(_ConnectionPtr connection, string stuClass, string courseName) {
	string sql = "select max(grade) max_grade from grade where stuId in (select id from student where stuClass = ?) and courseId in (select id from course where name = ?)";
	
	vector<string>* v = new vector<string>();
	v->push_back(stuClass);
	v->push_back(courseName);

	_RecordsetPtr record = executeSql(connection, sql.c_str(), v);
	if (record->BOF == -1) return NULL;//记录集为空

	return atof((char*)(_bstr_t)record->Fields->GetItem("max_grade")->Value);
}

double getClassMinGrade(_ConnectionPtr connection, string stuClass, string courseName) {
	string sql = "select min(grade) min_grade from grade where stuId in (select id from student where stuClass = ?) and courseId in (select id from course where name = ?)";
	
	vector<string>* v = new vector<string>();
	v->push_back(stuClass);
	v->push_back(courseName);

	_RecordsetPtr record = executeSql(connection, sql.c_str(), v);
	if (record->BOF == -1) return NULL;//记录集为空

	return atof((char*)(_bstr_t)record->Fields->GetItem("min_grade")->Value);
}