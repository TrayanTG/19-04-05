#include "Person.h"
#include <cstring>

Person::Person(const char* name, const char* ID, const char* phoneNumber)
{
    this->name=new char[strlen(name)+1];
    strcpy(this->name, name);
    strcpy(this->ID, ID);
    strcpy(this->phoneNumber, phoneNumber);
}

Person::Person(const Person& other)
{
    name=new char[strlen(other.name)+1];
    strcpy(name, other.name);
    strcpy(ID, other.ID);
    strcpy(phoneNumber, other.phoneNumber);
}

Person& Person::operator=(const Person& other)
{
    if(this==&other)return *this;
    delete[] name;
    name=new char[strlen(other.name)+1];
    strcpy(name, other.name);
    strcpy(ID, other.ID);
    strcpy(phoneNumber, other.phoneNumber);
    return *this;
}

Person::~Person()
{
    delete[] name;
}
