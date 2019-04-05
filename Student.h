#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "Person.h"
#include "Grade.h"

class Student: protected Person
{
    int fn;
    char *spec;
    int gradeCount;
    Grade *grades;
    int maxGrades()const;
    bool copyGrades(int gradeCount, const Grade *grades);
public:
    Student(const char *name = "", const char *ID = "", const char*phoneNumber = "", int fn = -1, const char *spec = "", int gradeCount = 0, const Grade *grades = nullptr);
    Student(const Student &other);
    Student& operator =(const Student &other);
    ~Student();

    friend std::ostream& operator <<(std::ostream &os, const Student &st);

    bool addGrade(const Grade &newGrade);
};

#endif //STUDENT_H_INCLUDED
