//
// Created by t3nshi on 20.01.24.
//

#ifndef SCHOOL_PARENT_H
#define SCHOOL_PARENT_H

#include "Passport.h"
#include "Student.h"
#include <random>
#include <vector>
class Parent : Passport {
private:
    vector<Passport> childs;
    int happy = 0;
public:
    Parent(string fName, string sName, short age, vector<Passport> childs);
    vector<Passport> getChilds();
     int getHappy();
};


#endif //SCHOOL_PARENT_H
