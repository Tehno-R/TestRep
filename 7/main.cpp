#include <iostream>
#include <string>
#include <vector>

#include "Passport.h"
#include "System.h"

using namespace std;

int main() {
    System subj1;
    Student *s1 = new Student("Nikita", "Kerjakov", 19);
    Student *s2 = new Student("Ivan", "Losevskiy", 18);
    Teacher *t1 = new Teacher("Marina", "Osipova", 30);
    subj1.addTeacher(t1);
    // part 1
    subj1.setMark(t1,s1, 5);
    subj1.setMark(t1,s1, 4);
    subj1.setMark(t1,s1, 3);
    subj1.setMark(t1,s1, 5);
    subj1.setMark(t1,s2, 5);
    subj1.setMark(t1,s2, 5);
    vector<short> nikitasMarks = subj1.getMarks(s1);
    vector<short> ivansMarks = subj1.getMarks(s2);
    cout << "Nikita's marks:";
    for (auto i : nikitasMarks) {
        cout << '\t' << i;
    }
    cout << endl;
    cout << "Ivan's marks:";
    for (auto i : ivansMarks) {
        cout << '\t' << i;
    }
    cout << endl;
    cout << s1->m_firstName + " excellent? - " << (subj1.excellent(s1) ? "Yes" : "No") << endl;
    cout << s2->m_firstName + " excellent? - " << (subj1.excellent(s2) ? "Yes" : "No") << endl;
    // part 2

    return 0;
}
