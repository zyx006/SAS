/*
* 学生表数据库操作接口实现
*/
#include"StudentDAO.h"

void addStudent(_ConnectionPtr connection, Student student) {
	string sql = "insert into student values(?,?,?,?,?)";

	vector<string>* v = new vector<string>();
	v->push_back(student.getId());
	v->push_back(student.getName());
	v->push_back(student.getSex());
	v->push_back(student.getStuClass());
	v->push_back(student.getStatus());

	executeSql(connection, sql.c_str(), v);
}

void deleteStudent(_ConnectionPtr connection, string id) {
	string sql = "delete from student where id = ?";

	vector<string>* v = new vector<string>();
	v->push_back(id);

	executeSql(connection, sql.c_str(), v);
}

void updateStudentClass(_ConnectionPtr connection, string id, string stuClass) {
	string sql = "update student set stuClass = ? where id = ?";

	vector<string>* v = new vector<string>();
	v->push_back(stuClass);
	v->push_back(id);

	executeSql(connection, sql.c_str(), v);
}

void updateStudentStatus(_ConnectionPtr connection, string id, string status) {
	string sql = "update student set status = ? where id = ?'";

	vector<string>* v = new vector<string>();
	v->push_back(status);
	v->push_back(id);

	executeSql(connection, sql.c_str(), v);
}

Student* getStudentById(_ConnectionPtr connection, string id) {
	string sql = "select * from student where id = ?";

	vector<string>* v = new vector<string>();
	v->push_back(id);

	_RecordsetPtr record = executeSql(connection, sql.c_str(), v);
	if (record->BOF == -1) return NULL;//记录集为空

	Student *student = new Student();
	student->setId((char*)(_bstr_t)record->Fields->GetItem("id")->Value);
	student->setName((char*)(_bstr_t)record->Fields->GetItem("name")->Value);
	student->setSex((char*)(_bstr_t)record->Fields->GetItem("sex")->Value);
	student->setStuClass((char*)(_bstr_t)record->Fields->GetItem("stuClass")->Value);
	student->setStatus((char*)(_bstr_t)record->Fields->GetItem("status")->Value);
	return student;
}

std::vector<Student>* getStudentByName(_ConnectionPtr connection, string name) {
	string sql = "select * from student where name = ?";
	
	vector<string>* v = new vector<string>();
	v->push_back(name);

	_RecordsetPtr record = executeSql(connection, sql.c_str(), v);
	if (record->BOF == -1) return NULL;//记录集为空

	std::vector<Student> *vs = new std::vector<Student>();
	Student* student;
	for (; !record->EndOfFile; record->MoveNext()) {
		student = new Student();
		student->setId((char*)(_bstr_t)record->Fields->GetItem("id")->Value);
		student->setName((char*)(_bstr_t)record->Fields->GetItem("name")->Value);
		student->setSex((char*)(_bstr_t)record->Fields->GetItem("sex")->Value);
		student->setStuClass((char*)(_bstr_t)record->Fields->GetItem("stuClass")->Value);
		student->setStatus((char*)(_bstr_t)record->Fields->GetItem("status")->Value);
		vs->push_back(*student);
	}
	return vs;
}

std::vector<Student>* getAllStudent(_ConnectionPtr connection) {
	string sql = "select * from student";

	_RecordsetPtr record = executeSql(connection, sql.c_str(), NULL);
	if (record->BOF == -1) return NULL;//记录集为空

	std::vector<Student>* v = new std::vector<Student>();
	Student* student;
	for (; !record->EndOfFile; record->MoveNext()) {
		student = new Student();
		student->setId((char*)(_bstr_t)record->Fields->GetItem("id")->Value);
		student->setName((char*)(_bstr_t)record->Fields->GetItem("name")->Value);
		student->setSex((char*)(_bstr_t)record->Fields->GetItem("sex")->Value);
		student->setStuClass((char*)(_bstr_t)record->Fields->GetItem("stuClass")->Value);
		student->setStatus((char*)(_bstr_t)record->Fields->GetItem("status")->Value);
		v->push_back(*student);
	}
	return v;
}