//
// Created by t3nshi on 19.01.24.
//

#include "System.h"

vector<short> System::getMarks(Passport *p) {
    for (auto &i : m_allMarks) {
        if (i.first == *p) return i.second;
    }
    return {};
}

bool System::excellent(Passport *p) {
    vector<short> *marks = nullptr;
    for (auto &i : m_allMarks) {
        if (i.first == *p)  marks = &i.second;
    }
    if (marks == nullptr) return false;
    else {
        if (std::all_of(marks->begin(), marks->end(), [](int i){ return i == 5; })) return true;
        return false;
    }
}

void System::setMark(Teacher *t, Student *s, short m) {
    for (auto i : m_allTeachers) {
        if (*(i.getPassport()) == *(t->getPassport())) {
            for (auto &j : m_allMarks) {
                if (*(j.first.getPassport()) == *(s->getPassport())) {
                    j.second.emplace_back(m);
                    return;
                }
            }
            m_allMarks.emplace_back(make_pair(Student{*s}, vector<short>{m}));
            return;
        }
    }
}

void System::addTeacher(Teacher *t) {
    for (auto i : m_allTeachers) {
        if (i.getPassport() == t->getPassport()) return;
    }
    m_allTeachers.emplace_back(*t);
}



