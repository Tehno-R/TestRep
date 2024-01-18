//
// Created by t3nshi on 19.01.24.
//

#ifndef SCHOOL_TEACHER_H
#define SCHOOL_TEACHER_H
#include <string>
#include "Passport.h"
using namespace std;

class Teacher : public Passport{
private:
    int happy = 3;

public:
    Teacher(string fName, string sName, short age);
    int getHappy();
};


#endif //SCHOOL_TEACHER_H
