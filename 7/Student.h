//
// Created by t3nshi on 19.01.24.
//

#ifndef SCHOOL_STUDENT_H
#define SCHOOL_STUDENT_H
#include "Passport.h"

class Student : public Passport{
public:
    Student(string fName, string sName, short age);
};


#endif //SCHOOL_STUDENT_H
