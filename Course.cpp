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
		string toStr = "Course{";
		toStr += "id='" + id + '\'' +
			", name='" + name + '\'' +
			'}';
		return toStr;
	}
private:
	string id;//¿Î³ÌºÅ
	string name;//¿Î³ÌÃû
};

#endif // !COURSE_CPP