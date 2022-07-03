/*
用于测试DAO功能是否能正常运行
*/
#if 0
#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include <stdio.h>  // wprintf
#include <iostream>
#include <locale.h> // setlocale
#include <string>
#include<vector>
#include "DBCUtils.h"
#include "StudentDAO.h"
#include "CourseDAO.h"
#include "GradeDAO.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "chs");
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

    _ConnectionPtr pconnect(_uuidof(Connection));
    string strConnect = "Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=stuAdminSystem;Data Source=LAPTOP-4DMOD6O5";
    pconnect->Open(strConnect.c_str(), "", "", NULL);

    //student
    /*
    Student* stu = new Student("2", "李四", "女", "计科00000", "休学");
    addStudent(pconnect, *stu);
    deleteStudent(pconnect, "4");
    updateStudentClass(pconnect, "3", "软件12004");
    updateStudentStatus(pconnect, "3", "休学");

    Student student = getStudentById(pconnect, "1");
    cout << student.toString() << "\n";

    vector<Student> v = getStudentByName(pconnect, "张三");
    for (int i = 0; i < v.size(); i++)
        cout << v[i].toString() << "\n";
    */

    //course
    /*
    Course* course1 = new Course("A001","高数");
    Course* course2 = new Course("A002","C语言");
    Course* course3 = new Course("A003","体育");
    addCourse(pconnect, *course1);
    addCourse(pconnect, *course2);
    addCourse(pconnect, *course3);
    
    deleteCourse(pconnect, "A002");
    updateCourseName(pconnect, "A003", "物理");

    Course cou = getCourseById(pconnect, "A001");
    cout << cou.toString() << "\n";

    vector<Course> v = getCourseByName(pconnect, "高数");
    for (int i = 0; i < v.size(); i++)
        cout << v[i].toString() << "\n";
    */

    //grade
    /*
    Grade* course1 = new Grade("1","A001","95");
    Grade* course2 = new Grade("1","A001-1", "95");
    Grade* course3 = new Grade("1","A003", "95");
    Grade* course4 = new Grade("2","A001", "95");
    Grade* course5 = new Grade("2","A003", "95");
    addGrade(pconnect, *course1);
    addGrade(pconnect, *course2);
    addGrade(pconnect, *course3);
    addGrade(pconnect, *course4);
    addGrade(pconnect, *course5);
    
    deleteOnesGrade(pconnect, "1","A001-1");
    deleteGradeByStuId(pconnect, "1");
    deleteGradeByCourseId(pconnect, "A001");
    

    updateOnesGrade(pconnect,"1","A001-1","98.4");
    
    Grade gra = getOnesGrade(pconnect, "1","A001");
    cout << gra.toString() << "\n";

    cout << "\n";

    vector<Grade> v = getGradeByStuId(pconnect, "1");
    for (int i = 0; i < v.size(); i++)
        cout << v[i].toString() << "\n";

    cout << "\n";

    vector<Grade> v1 = getGradeByCourseId(pconnect, "A001");
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i].toString() << "\n";
    */
    CoUninitialize();
    return 0;
}
#endif