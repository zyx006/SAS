#include"GradeDAO.h"

void addGrade(_ConnectionPtr connection, Grade grade) {
	string sql = "insert into grade values('" + grade.getStuId() + "'," +
		"'" + grade.getCourseId() + "'," +
		"'" + grade.getGradeStr() + "')";

	connection->Execute(sql.c_str(), NULL, (long)0);
}

void deleteOnesGrade(_ConnectionPtr connection, string stuId, string courseId) {
	string sql = "delete from grade where stuId = '" + stuId + "\' and courseId = \'" + courseId + "'";

	connection->Execute(sql.c_str(), NULL, (long)0);
}

void deleteGradeByStuId(_ConnectionPtr connection, string stuId) {
	string sql = "delete from grade where stuId = '" + stuId + "'";

	connection->Execute(sql.c_str(), NULL, (long)0);
}

void deleteGradeByCourseId(_ConnectionPtr connection, string courseId) {
	string sql = "delete from grade where courseId = '" + courseId + "'";

	connection->Execute(sql.c_str(), NULL, (long)0);
}

void updateOnesGrade(_ConnectionPtr connection, string stuId, string courseId, string grade) {
	string sql = "update grade set grade = " + grade + " where stuId = '" + stuId + "\' and courseId = \'" + courseId + "'";

	connection->Execute(sql.c_str(), NULL, (long)0);
}

Grade& getOnesGrade(_ConnectionPtr connection, string stuId,string courseId) {
	string sql = "select * from grade where stuId = '" + stuId + "\' and courseId = \'" + courseId + "'";
	_RecordsetPtr record = connection->Execute(sql.c_str(), NULL, (long)0);

	Grade* grade = new Grade();
	grade->setStuId((char*)(_bstr_t)record->Fields->GetItem("stuId")->Value);
	grade->setCourseId((char*)(_bstr_t)record->Fields->GetItem("courseId")->Value);
	grade->setGrade((char*)(_bstr_t)record->Fields->GetItem("grade")->Value);
	return *grade;
}

std::vector<Grade>& getGradeByStuId(_ConnectionPtr connection, string stuId) {
	string sql = "select * from grade where stuId = '" + stuId + "'";
	_RecordsetPtr record = connection->Execute(sql.c_str(), NULL, (long)0);

	std::vector<Grade>* v = new std::vector<Grade>();
	Grade* grade;
	for (; !record->EndOfFile; record->MoveNext()) {
		grade = new Grade();
		grade->setStuId((char*)(_bstr_t)record->Fields->GetItem("stuId")->Value);
		grade->setCourseId((char*)(_bstr_t)record->Fields->GetItem("courseId")->Value);
		grade->setGrade((char*)(_bstr_t)record->Fields->GetItem("grade")->Value);
		v->push_back(*grade);
	}
	return *v;
}

std::vector<Grade>& getGradeByCourseId(_ConnectionPtr connection, string courseId) {
	string sql = "select * from grade where courseId = '" + courseId + "'";
	_RecordsetPtr record = connection->Execute(sql.c_str(), NULL, (long)0);

	std::vector<Grade>* v = new std::vector<Grade>();
	Grade* grade;
	for (; !record->EndOfFile; record->MoveNext()) {
		grade = new Grade();
		grade->setStuId((char*)(_bstr_t)record->Fields->GetItem("stuId")->Value);
		grade->setCourseId((char*)(_bstr_t)record->Fields->GetItem("courseId")->Value);
		grade->setGrade((char*)(_bstr_t)record->Fields->GetItem("grade")->Value);
		v->push_back(*grade);
	}
	return *v;
}