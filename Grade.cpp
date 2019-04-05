#include "Grade.h"
#include <cstring>
#

Grade::Grade(float grade, const char* subject): grade(grade)
{
    this->subject=new char[strlen(subject)+1];
    strcpy(this->subject, subject);
}

Grade::Grade(const Grade& other): grade(other.grade)
{
    subject=new char[strlen(other.subject)+1];
    strcpy(subject, other.subject);
}

Grade& Grade::operator=(const Grade& other)
{
    if(this==&other)return *this;
    delete[] subject;
    grade=other.grade;
    subject=new char[strlen(other.subject)+1];
    strcpy(subject, other.subject);
    return *this;
}

Grade::~Grade()
{
    delete subject;
}

std::ostream& operator<<(std::ostream &os, const Grade &gr)
{
    return os<<gr.subject<<": "<<gr.grade;
}
