//
// Created by t3nshi on 19.01.24.
//

#include "Teacher.h"

Teacher::Teacher(string fName, string sName, short age) : Passport(fName, sName, age) {
    srand(time(nullptr));
    happy = (rand()%10) + 1;
    this->hihihaha = rand()%2;
    if (hihihaha) favMark = (rand()%5) + 1;
    period = rand()%10;
}
int Teacher::getHappy() {return this->happy; }

bool Teacher::getHihihaha() {
    return this->hihihaha;
}

short Teacher::getFavmark() {
    return this->favMark;
}

void Teacher::marked() {
    curPeriod++;
    if (curPeriod == period) {
        curPeriod = 0;
        happy = (rand()%10) + 1;
    }
}
