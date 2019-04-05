#include "Student.h"
#include <cstring>

bool Student::copyGrades(int gradeCount, const Grade* grades)
{
    delete[] this->grades;
    this->gradeCount = gradeCount;
    this->grades = nullptr;
    if(!gradeCount)return true;

    this->grades = new Grade[gradeCount];
    if(this->grades == nullptr)return false;
    for(int i=0;i<gradeCount;i++)this->grades[i]=grades[i];
    return true;
}

Student::Student(const char *name, const char *ID, const char*phoneNumber, int fn, const char* spec, int gradeCount, const Grade *grades): Person(name, ID, phoneNumber), fn(fn)
{
    this->spec = new char[strlen(spec)+1];
    strcpy(this->spec, spec);
    copyGrades(gradeCount, grades);
}

Student::Student(const Student& other): Person(other), fn(other.fn)
{
    spec = new char[strlen(other.spec)+1];
    strcpy(spec, other.spec);
    copyGrades(other.gradeCount, other.grades);
}

Student& Student::operator=(const Student& other)
{
    if(this==&other)return *this;
    delete[] spec;
    Person::operator=(other);
    fn=other.fn;
    spec = new char[strlen(other.spec)+1];
    strcpy(spec, other.spec);
    copyGrades(other.gradeCount, other.grades);
}

Student::~Student()
{
    delete[] spec;
}

int Student::maxGrades()const
{
    return sizeof(grades)/sizeof(Grade);
}

bool Student::addGrade(const Grade& newGrade)
{
    if(gradeCount==maxGrades())
    {
        Grade *temp=new Grade[maxGrades()*2];
        for(int i=0;i<gradeCount;i++)temp[i] = grades[i];
        temp[gradeCount++] = newGrade;
        delete[] grades;
        grades=temp;
        return true;
    }
    grades[gradeCount++]=newGrade;
    return true;
}
