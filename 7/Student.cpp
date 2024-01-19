//
// Created by t3nshi on 19.01.24.
//

#include "Student.h"

Student::Student(string fName, string sName, short age) : Passport(fName, sName, age) {}

void Student::wasMarked() {
    this->marked = true;
}

bool Student::getMarked() {
    return this->marked;
}

bool Student::dropMarked() {
    return this->marked = false;
};