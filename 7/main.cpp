#include <iostream>
#include <string>
#include <vector>

#include "System.h"

using namespace std;

int main() {
    System subj1;
    Student *s1 = new Student("Nikita", "Kerjakov", 19);
    Student *s2 = new Student("Ivan", "Losevskiy", 18);
    Student *s3 = new Student("Gleb", "Mlakir", 20);
    Student *s4 = new Student("Vlad", "Rodohleb", 15);
    Teacher *t1 = new Teacher("Marina", "Osipova", 30);
    Teacher *t2 = new Teacher("Alena", "Stepanowa", 999);
    Parent *p1 = new Parent("Olga", "Mlakir", 38, vector<Passport>{*(s1->getPassport())});
    Parent *p2 = new Parent("Galya", "Venik", 32, vector<Passport>{*(s1->getPassport()),*(s4->getPassport())});
    Parent *p3 = new Parent("Vasilisa", "Alexandrovna", 74, vector<Passport>{*(s2->getPassport())});
    subj1.addTeacher(t1);
    subj1.addTeacher(t2);
    // part 1
    subj1.setMark(t1,s1, 5);
    subj1.setMark(t2,s4, 4);
    subj1.setMark(t1,s4, 3);
    subj1.setMark(t1,s1, 5);
    subj1.setMark(t2,s2, 5);
    subj1.setMark(t1,s1, 5);
    subj1.setMark(t1,s3, 4);
    subj1.setMark(t2,s3, 3);
    subj1.setMark(t2,s1, 5);
    subj1.setMark(t1,s2, 2);
    subj1.setMark(t1,s2, 1);

    cout << s1->m_firstName + " excellent? - " << (subj1.excellent(s1) ? "Yes" : "No") << endl;
    cout << s2->m_firstName + " excellent? - " << (subj1.excellent(s2) ? "Yes" : "No") << endl;
    cout << endl;
    // part 2
    subj1.doLesson(t1);
    // part ???
    subj1.parentSpeak(p1);
    subj1.meeting(vector<Parent>{*p1, *p2}, t1);
    return 0;
}
