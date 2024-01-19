//
// Created by t3nshi on 19.01.24.
//

#ifndef SCHOOL_PASSPORT_H
#define SCHOOL_PASSPORT_H
#include <string>
using namespace std;

class Passport {
public:
    const string m_firstName;
    const string m_secondName;
    const short m_age;
    Passport(string firstName, string secondName, short age);
    bool operator==(Passport &other) {
        if ((this->m_firstName == other.m_firstName) &&
            (this->m_secondName == other.m_secondName) &&
            (this->m_age == other.m_age)) return true;
        else return false;
    };
//    Passport& operator=(const Passport &other) {
//        m_firstName = other.m_firstName;
//        m_secondName = other.m_secondName;
//        m_age = other.m_age;
//    };

    Passport* getPassport();
};


#endif //SCHOOL_PASSPORT_H
