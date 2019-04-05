#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

class Person
{
protected:
    char *name;
    char ID[11];
    char phoneNumber[11];
public:
    Person(const char *name = "", const char *ID = "", const char*phoneNumber = "");
    Person(const Person &other);
    Person& operator =(const Person &other);
    ~Person();
};

#endif // PERSON_H_INCLUDED
