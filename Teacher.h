#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED

#include "Person.h"
#include <iostream>

class Teacher: protected Person
{
    char *subject;
public:
    Teacher(const char *name = "", const char *ID = "", const char*phoneNumber = "", const char *subject = "");
    Teacher(const Teacher &other);
    Teacher& operator =(const Teacher &other);
    ~Teacher();

    friend std::ostream& operator <<(std::ostream &os, const Teacher &t);


};

#endif //TEACHER_H_INCLUDED
