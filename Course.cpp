/*
* �γ̱�DAO
*/
#ifndef COURSE_CPP
#define COURSE_CPP

#include<string>
using std::string;
class Course
{
public:
	Course() { ; }
	Course(string id, string name) {
		this->id = id;
		this->name = name;
	}

	string getId() { return id; }
	void setId(string id) { this->id = id; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }

	string toString() {
		return id + "\t" + name;
	}
private:
	string id;//�γ̺�
	string name;//�γ���
};

#endif // !COURSE_CPP