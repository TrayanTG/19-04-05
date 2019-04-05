#include "Teacher.h"
#include <cstring>

Teacher::Teacher(const char* name, const char* ID, const char* phoneNumber, const char* subject): Person(name, ID, phoneNumber)
{
    this->subject = new char[strlen(subject)+1];
    strcpy(this->subject, subject);
}

Teacher::Teacher(const Teacher& other): Person(other)
{
    subject = new char[strlen(other.subject)+1];
    strcpy(subject, other.subject);
}

Teacher& Teacher::operator=(const Teacher& other)
{
    if(this==&other)return *this;
    delete[] subject;
    Person::operator=(other);
    subject = new char[strlen(other.subject)+1];
    strcpy(subject, other.subject);
    return *this;
}

Teacher::~Teacher()
{
    delete[] subject;
}

std::ostream& operator <<(std::ostream &os, const Teacher &t)
{
    return os<<t.name<<" teaches "<<t.subject;

}
