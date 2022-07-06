/*
* 学生表DAO
*/
#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using std::string;

class Student {
public:
	Student() { ; }
	Student(string id, string name, string sex, string stuClass, string status) {
		this->id = id;
		this->name = name;
		this->sex = sex;
		this->stuClass = stuClass;
		this->status = status;
	}
	string getId() { return id; }
	void setId(string id) { this->id = id; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }
	string getSex() { return sex; }
	void setSex(string sex) { this->sex = sex; }
	string getStuClass() { return stuClass; }
	void setStuClass(string stuClass) { this->stuClass = stuClass; }
	string getStatus() { return status; }
	void setStatus(string status) { this->status = status; }

	string toString() {
		return id + "\t" + name + "\t" + sex + "\t" + stuClass + "\t" + status;
	}
private:
	string id;//学号
	string name;//姓名
	string sex;//性别
	string stuClass;//班级
	string status;//状态（在读、休学、退学）
};

#endif // !STUDENT_H