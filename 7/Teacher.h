//
// Created by t3nshi on 19.01.24.
//

#ifndef SCHOOL_TEACHER_H
#define SCHOOL_TEACHER_H
#include <string>
#include "random"
#include "Passport.h"
using namespace std;

class Teacher : public Passport{
private:
    bool hihihaha = false;
    int happy = 3;
    short favMark = 0;
public:
    Teacher(string fName, string sName, short age);
    int getHappy();
    bool getHihihaha();
    short getFavmark();
};


#endif //SCHOOL_TEACHER_H
