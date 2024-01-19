//
// Created by t3nshi on 19.01.24.
//

#ifndef SCHOOL_SYSTEM_H
#define SCHOOL_SYSTEM_H
#include "Passport.h"
#include "Student.h"
#include "Teacher.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <iostream>


class System {
private:
    vector<pair<Student, vector<short>>> m_allMarks;
    vector<Teacher> m_allTeachers;
    int solveMark(Teacher*, Student*, int);
public:
    vector<short> getMarks(Passport *p);
    bool excellent(Passport *p);
    void setMark(Teacher* t, Student* s, short m);
    void addTeacher(Teacher* t);
    void doLesson(Teacher* t);
};


#endif //SCHOOL_SYSTEM_H
