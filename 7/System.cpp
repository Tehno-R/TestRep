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
                    j.second.emplace_back(solveMark(t, s, m));
                    t->marked();
                    j.first.wasMarked();
                    return;
                }
            }
            m = solveMark(t,s,m);
            m_allMarks.emplace_back(make_pair(Student{*s}, vector<short>{m}));
            t->marked();
            (m_allMarks.end()-1)->first.wasMarked();
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

int System::solveMark(Teacher *t, Student *s, int m) {
    if (t->getHihihaha()) return t->getFavmark();
    if (!m) m = 1;
    return (t->getHappy() + (excellent(s) ? 1 : 0)/2)+1 * m;
}

void System::doLesson(Teacher *t) {
    srand(time(nullptr));
    bool flag = false;
    for (auto i : m_allTeachers) {
        if (*(i.getPassport()) == *(t->getPassport())) {
            flag = true;
            break;
        }
    }
    if (!flag) return;
    cout << "Teacher: " << t->m_firstName + ' ' + t->m_secondName << endl;
    vector<Student> came;
    cout << "On lesson are:";
    for (int i = 0; i < m_allMarks.size(); i += rand()) {
        came.emplace_back(m_allMarks[i].first);
        cout << '\t' << (came.end()-1)->m_firstName + ' ' + (came.end()-1)->m_secondName;
    }
    cout << endl;
    for (int i = 0; i < came.size(); ++i) {
        setMark(t, &came[i], (rand()%5)+1);
    }
    cout << "Marks have been made" << endl;
}

void System::parentSpeak(Parent *p) {
    bool flag1 = false;
    bool flag2 = false;
    vector<Passport> childs = p->getChilds();
    for (auto i : childs) {
        for (auto j : m_allMarks) {
            if (i == *(j.first.getPassport())) {
                flag1 = excellent(&i);
                flag2 = p->getHappy()>=5;
                if (flag1 || p->getOld()) cout << i.m_firstName + " is excellent, Im proud" << endl;
                if (flag2 || p->getOld()) cout << "I very very love my " + i.m_firstName << endl;
            }
        }
    }
}

void System::meeting(vector<Parent> parents, Teacher *t) { //                                   Схалтурил
    vector<Passport> was;
    cout << "Start meeting" << endl;
    if (t != nullptr) cout << t->getPassport()->m_firstName + ' ' + t->getPassport()->m_secondName + " came to meeting" << endl;
    else {
        cout << "Teacher not come" << endl;
        cout << "Meeting completed" << endl;
        return;
    }
    vector<Passport> childs;
    for (auto i : parents) {
        childs = i.getChilds();
        for (auto j : childs) {
            for (auto &k : m_allMarks) {
                if (*(j.getPassport()) == *(k.first.getPassport()))  {
                    if (k.first.getMarked()) {
                        parentSpeak(&i);
                        if (i.getOld()) cout << childs[rand()%childs.size()].getPassport()->m_firstName
                        << " is weird child hihihi" << endl;
                        k.first.dropMarked();
                    }
                    was.emplace_back(*(k.first.getPassport()));
                }
            }
        }
    }
    cout << "Not came: " << endl;
    for (auto i : m_allMarks) {
        bool flag = true;
        for (auto j : was) {
            if (*(j.getPassport()) == *(i.first.getPassport())) {
                flag = false;
                break;
            }
        }
        if (flag) cout << i.first.getPassport()->m_firstName + ' ' + i.first.getPassport()->m_secondName << endl;
    }
    cout << "Meeting completed" << endl;
}



