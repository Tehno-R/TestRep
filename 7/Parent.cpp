//
// Created by t3nshi on 20.01.24.
//

#include "Parent.h"


Parent::Parent(string fName, string sName, short age, vector<Passport> childs) : Passport(fName, sName, age) {
    for (auto i : childs) {
        this->childs.emplace_back(i);
    }
    srand(time(nullptr));
    this->happy = rand()%10;
}

vector<Passport> Parent::getChilds() {
    return this->childs;
}

int Parent::getHappy() {
    return this->happy;
}
