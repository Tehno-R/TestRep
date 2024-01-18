//
// Created by t3nshi on 19.01.24.
//

#include "Passport.h"

Passport::Passport(string firstName, string secondName, short age):
                                                        m_firstName(firstName), m_secondName(secondName), m_age(age){};

Passport* Passport::getPassport() {return this;}