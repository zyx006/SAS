/*
* 课程表数据库操作接口实现
*/
#include"CourseDAO.h"

void addCourse(_ConnectionPtr connection, Course course) {
	string sql = "insert into course values(?,?)";

	vector<string>* v = new vector<string>();
	v->push_back(course.getId());
	v->push_back(course.getName());

	executeSql(connection, sql.c_str(), v);
}

void deleteCourse(_ConnectionPtr connection, string id) {
	string sql = "delete from course where id = ?";

	vector<string>* v = new vector<string>();
	v->push_back(id);

	executeSql(connection, sql.c_str(), v);
}

void updateCourseName(_ConnectionPtr connection, string id, string name) {
	string sql = "update course set name = ? where id = ?";

	vector<string>* v = new vector<string>();
	v->push_back(name);
	v->push_back(id);

	executeSql(connection, sql.c_str(), v);
}

Course* getCourseById(_ConnectionPtr connection, string id) {
	string sql = "select * from course where id = ?";
	
	vector<string>* v = new vector<string>();
	v->push_back(id);
	
	_RecordsetPtr record = executeSql(connection, sql.c_str(), v);
	if (record->BOF == -1) return NULL;//记录集为空

	Course* course = new Course();
	course->setId((char*)(_bstr_t)record->Fields->GetItem("id")->Value);
	course->setName((char*)(_bstr_t)record->Fields->GetItem("name")->Value);
	return course;
}

Course* getCourseByName(_ConnectionPtr connection, string name) {
	string sql = "select * from course where name = ?";

	vector<string>* v = new vector<string>();
	v->push_back(name);

	_RecordsetPtr record = executeSql(connection, sql.c_str(), v);
	if (record->BOF == -1) return NULL;//记录集为空

	Course* course = new Course();
	course->setId((char*)(_bstr_t)record->Fields->GetItem("id")->Value);
	course->setName((char*)(_bstr_t)record->Fields->GetItem("name")->Value);
	return course;
}

std::vector<Course>* getAllCourse(_ConnectionPtr connection) {
	string sql = "select * from course";
	_RecordsetPtr record = executeSql(connection, sql.c_str(), NULL);
	if (record->BOF == -1) return NULL;//记录集为空

	std::vector<Course>* v = new std::vector<Course>();
	Course* course;
	for (; !record->EndOfFile; record->MoveNext()) {
		course = new Course();
		course->setId((char*)(_bstr_t)record->Fields->GetItem("id")->Value);
		course->setName((char*)(_bstr_t)record->Fields->GetItem("name")->Value);
		v->push_back(*course);
	}
	return v;
}