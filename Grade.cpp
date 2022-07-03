#ifndef GRADE_CPP
#define GRADE_CPP

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
		string toStr = "Grade{";
		toStr += "stuId='" + stuId + '\'' +
			", courseId='" + courseId + '\'' +
			", grade='" + grade + '\'' +
			'}';
		return toStr;
	}
private:
	string stuId;
	string courseId;
	string grade;
};

#endif // !GRADE_CPP