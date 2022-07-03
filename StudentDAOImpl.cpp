#include"StudentDAO.h"

void addStudent(_ConnectionPtr connection, Student student) {
	string sql = "insert into student values('" + student.getId() + "'," +
		"'" + student.getName() + "'," +
		"'" + student.getSex() + "'," +
		"'" + student.getStuClass() + "'," +
		"'" + student.getStatus() + "')";

	connection->Execute(sql.c_str(), NULL, (long)0);
}

void deleteStudent(_ConnectionPtr connection, string id) {
	string sql = "delete from student where id = '" + id + "'";

	connection->Execute(sql.c_str(), NULL, (long)0);
}

void updateStudentClass(_ConnectionPtr connection, string id, string stuClass) {
	string sql = "update student set stuClass = '" + stuClass + "\' where id = \'" + id + "'";

	connection->Execute(sql.c_str(), NULL, (long)0);
}

void updateStudentStatus(_ConnectionPtr connection, string id, string status) {
	string sql = "update student set status = '" + status + "\' where id = \'" + id + "'";

	connection->Execute(sql.c_str(), NULL, (long)0);
}

Student& getStudentById(_ConnectionPtr connection, string id) {
	string sql = "select * from student where id = '" + id + "'";
	_RecordsetPtr record = connection->Execute(sql.c_str(), NULL, (long)0);

	Student *student = new Student();
	student->setId((char*)(_bstr_t)record->Fields->GetItem("id")->Value);
	student->setName((char*)(_bstr_t)record->Fields->GetItem("name")->Value);
	student->setSex((char*)(_bstr_t)record->Fields->GetItem("sex")->Value);
	student->setStuClass((char*)(_bstr_t)record->Fields->GetItem("stuClass")->Value);
	student->setStatus((char*)(_bstr_t)record->Fields->GetItem("status")->Value);
	return *student;
}

std::vector<Student>& getStudentByName(_ConnectionPtr connection, string name) {
	string sql = "select * from student where name = '" + name + "'";
	_RecordsetPtr record = connection->Execute(sql.c_str(), NULL, (long)0);

	std::vector<Student> *v = new std::vector<Student>();
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
	return *v;
}