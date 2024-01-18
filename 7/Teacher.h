//
// Created by t3nshi on 19.01.24.
//

#ifndef SCHOOL_TEACHER_H
#define SCHOOL_TEACHER_H
#include <string>
#include "Passport.h"
using namespace std;

class Teacher : public Passport{
public:
    Teacher(string fName, string sName, short age);
};


#endif //SCHOOL_TEACHER_H
