#ifndef GRADE_H_INCLUDED
#define GRADE_H_INCLUDED

#include <iostream>

class Grade
{
    float grade;
    char *subject;
public:
    Grade(float grade = 0, const char *subject = nullptr);
    Grade(const Grade &other);
    Grade& operator =(const Grade &other);
    ~Grade();

    friend std::ostream& operator<<(std::ostream &os, const Grade &gr);
};

#endif //GRADE_H_INCLUDED
