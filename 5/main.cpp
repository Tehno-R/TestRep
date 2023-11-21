#include <iostream>
#include <string>

using namespace std;

class Human{
private:
    struct statistic{
        float power;
        float intellect;
        float agility;
    };

    bool gender; // Условимся что женщина это false а мужчина это true;
    string name;
    int hp = 100;
    int level = 1;
    statistic stat;
    int balance = 0;

public:
    bool getGender() const {
        return this->gender;
    }

    string getName() const {
        return this->name;
    }

    statistic getStat() const {
        return this->stat;
    }

    Human(string n, int p, int i, int a, bool g){
        this->name = n;
        this->stat.power = p;
        this->stat.intellect = i;
        this->stat.agility = a;
        this->gender = g;
    }
    Human(string n, const Human mom, const Human dad){
        this->name = n;
        const float koef = 0.2f;

        statistic momstat = mom.stat;
        statistic dadstat = dad.stat;
        this->stat.power = (momstat.power + dadstat.power)/koef;
        this->stat.intellect = (momstat.intellect + dadstat.intellect)/koef;
        this->stat.agility = (momstat.agility + dadstat.agility)/koef;

        this->gender = rand() % 2;
    }


    void sendMoneyTo(Human &b, int howMuch) {
        if (this->balance >= howMuch) {
            this->balance -= howMuch;
            b.getMoney(howMuch);
        }
    }
    void printBalance() {
        cout << this->name << "'s balance: " << this->balance << '\n';
    }
    void printStat(){
        cout << this->name << " stat:" << '\n'
        << '\t' << "Power: " << this->stat.power << '\n'
        << '\t' << "Intellect: " << this->stat.intellect << '\n'
        << '\t' << "Agility: " << this->stat.agility << '\n';
    }

protected:
    void getMoney(int money) {
        this->balance += money;
    }
};

class IWork { // Я буду работать :(
public:
    virtual void doWork() {};
};

class Miner:public Human, public IWork{
private:
    unsigned int countMinedStones = 0;
public:

    Miner(const string &n, int p, int i, int a, bool g) : Human(n, p, i, a, g) {}
    Miner(const string &n, Human a, Human b) : Human(n, a, b) {}

    void doWork() override{ // Шахтер типо копает поетому у него там что то с силой
        getMoney(this->getStat().power + 3.2f * countMinedStones);
    }
};
class Coder:public Human, public IWork{
private:
    unsigned int countErrors = 0;
public:

    Coder(const string &n, int p, int i, int a, bool g) : Human(n, p, i, a, g) {}
    Coder(const string &n, Human a, Human b) : Human(n, a, b) {}

    void doWork() override{ // Ну кодерам нужен так называемый intellect
        return getMoney(this->getStat().intellect + 0.404f * countErrors);
    }

    void hackWorld() { // Очевидно что любой программист может взломать мир
//        вариант ниже хотел использовать но русские символы выводятся криво всё такое
//        cout << this->getName() << ((this->getGender() == false) ? " взломала":" взломал") << " мир.";
        cout << this->getName() << " have hacked" << " world." << '\n';
    }
};
class Thief:public Human, public IWork{
public:

    Thief(const string &n, int p, int i, int a, bool g) : Human(n, p, i, a, g) {}
    Thief(const string &n, Human a, Human b) : Human(n, a, b) {}

    void doWork() override{ // ...а ворам ловкость :)
        getMoney(this->getStat().agility * 0.111000101001100110100101f); // tip: 0 в начале не учитывать
    }

    void getRich() {
        getMoney(999999999); // оверфлоу как цикл жизни вора: сначало богатеть потом нищать...
    }
};


int main() {
    srand(time(nullptr));
    Thief person1("Diluc", 80, 60, 60, false);
    Miner person2("Jean", 30, 60, 40, false);
    Coder person3("Something", person1, person2);

    for (int i = 0; i < 100; ++i) {
        person3.doWork(); // усердно работает
    }
    person3.printBalance();
    person1.getRich();
    person1.printBalance();
    person1.sendMoneyTo(person3, 50000);
    person1.printBalance();
    person3.printBalance();
    person3.hackWorld();
    person2.printStat();
    return 0;
}
