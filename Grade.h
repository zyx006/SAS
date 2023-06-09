/*
* 成绩表DAO
*/
#ifndef GRADE_H
#define GRADE_H

#include<string>
using std::string;

class Grade {
public:
	Grade() { ; }
	Grade(string stuId, string courseId, string grade) {
		this->stuId = stuId;
		this->courseId = courseId;
		this->grade = grade;
	}

	string getStuId() { return stuId; }
	void setStuId(string stuId) { this->stuId = stuId; }
	string getCourseId() { return courseId; }
	void setCourseId(string courseId) { this->courseId = courseId; }
	double getGrade() { return atof(grade.c_str()); }
	string getGradeStr() { return grade; }
	void setGrade(string grade) { this->grade = grade; }

	string toString() {
		return stuId + "\t" + courseId + "\t" + grade;
	}
private:
	string stuId;//学号
	string courseId;//课程号
	string grade;//成绩
};

#endif // !GRADE_H