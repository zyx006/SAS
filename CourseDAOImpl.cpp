#include"CourseDAO.h"

void addCourse(_ConnectionPtr connection, Course course) {
	string sql = "insert into course values('" + course.getId() + "'," +
		"'" + course.getName() + "')";

	connection->Execute(sql.c_str(), NULL, (long)0);
}

void deleteCourse(_ConnectionPtr connection, string id) {
	string sql = "delete from course where id = '" + id + "'";

	connection->Execute(sql.c_str(), NULL, (long)0);
}

void updateCourseName(_ConnectionPtr connection, string id, string name) {
	string sql = "update course set name = '" + name + "\' where id = \'" + id + "'";

	connection->Execute(sql.c_str(), NULL, (long)0);
}

Course* getCourseById(_ConnectionPtr connection, string id) {
	string sql = "select * from course where id = '" + id + "'";
	_RecordsetPtr record = connection->Execute(sql.c_str(), NULL, (long)0);
	if (record->BOF == -1) return NULL;

	Course* course = new Course();
	course->setId((char*)(_bstr_t)record->Fields->GetItem("id")->Value);
	course->setName((char*)(_bstr_t)record->Fields->GetItem("name")->Value);
	return course;
}

Course* getCourseByName(_ConnectionPtr connection, string name) {
	string sql = "select * from course where name = '" + name + "'";
	_RecordsetPtr record = connection->Execute(sql.c_str(), NULL, (long)0);
	if (record->BOF == -1) return NULL;

	Course* course = new Course();
	course->setId((char*)(_bstr_t)record->Fields->GetItem("id")->Value);
	course->setName((char*)(_bstr_t)record->Fields->GetItem("name")->Value);
	return course;
}

std::vector<Course>* getAllCourse(_ConnectionPtr connection) {
	string sql = "select * from course";
	_RecordsetPtr record = connection->Execute(sql.c_str(), NULL, (long)0);
	if (record->BOF == -1) return NULL;

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