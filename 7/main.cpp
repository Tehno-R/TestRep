#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Passport {
public:
    const string m_firstName;
    const string m_secondName;
    const short m_age;
    Passport(string firstName, string secondName, short age)
    : m_firstName(firstName), m_secondName(secondName), m_age(age){};

    bool operator==(Passport &other) {
        if ((this->m_firstName == other.m_firstName) &&
            (this->m_secondName == other.m_secondName) &&
            (this->m_age == other.m_age)) return true;
        else return false;
    }
};

class System {
private:
    vector<pair<Passport, vector<short>>> m_allMarks;
public:
    void setMark(Passport *p, short mark) {
        for (auto &i : m_allMarks) {
            if (i.first == *p) i.second.emplace_back(mark);
            return;
        }
        m_allMarks.emplace_back(make_pair(*p,vector<short>{mark}));
        return;
    }
    vector<short> getMarks(Passport *p) {

        for (auto &i : m_allMarks) {
            if (i.first == *p) return i.second;
        }
        return {};
    }
    bool excellent(Passport *p) {
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
};

class Student : public Passport{
public:
    Student(string fName, string sName, short age) : Passport(fName, sName, age) {};
    Passport getInfo() {return Student(m_firstName, m_secondName, m_age);}
};


int main() {
    System school;
    Student *s1 = new Student("Nikita", "Kerjakov", 19);
    school.setMark(s1, 5);
    school.setMark(s1, 4);
    school.setMark(s1, 3);
    school.setMark(s1, 5);
    vector<short> nikitasMarks = school.getMarks(s1);
    cout << "Nikita's marks:";
    for (auto i : nikitasMarks) {
        cout << '\t' << i;
    }
    cout << endl;
    return 0;
}
