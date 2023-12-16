#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class IPrintble {
public:
    virtual string printIt() {};
};

class Ingridient : public IPrintble{
    string name;
public:
    Ingridient(string n) {
        this->name = n;
    }
    string getName() {return this->name;}

    string printIt() override {
        return name;
    }
};

class Addble : public Ingridient {
private:
    unsigned short count = 1;
    const unsigned short price = 0;
public:
    Addble(string name, unsigned short price) : Ingridient(name), price(price) {}
    int getCount() {return this->count;}
    int getPrice() {return this->price;}
    void add() {count++;}
    void remove() {count--;}

    string printIt() override {
        return this->getName() + ", Count: " + to_string(this->count);
    }
};

class Tomato : public Ingridient {
public:
    Tomato() : Ingridient("Tomato") {}
};
class Pickle : public Ingridient {
public:
    Pickle() :  Ingridient("Pickle") {}
};
class Parmezan : public Ingridient {
public:
    Parmezan() : Ingridient("Parmezan") {}
};
class Olive : public Ingridient {
public:
    Olive() : Ingridient("Olive") {}
};
class Jalapeno : public Ingridient {
public:
    Jalapeno() : Ingridient("Jalapeno") {}
};
class Peperoni : public Ingridient {
public:
    Peperoni() : Ingridient("Peperoni") {}
};
class Chiken : public Ingridient {
public:
    Chiken() : Ingridient("Chiken") {}
};
class Seafood : public Ingridient {
public:
    Seafood() : Ingridient("Seafood") {}
};
class Chees : public Addble {
public:
    Chees() : Addble("Chees", 5) {}
};
class Salt : public Addble {
public:
    Salt() : Addble("Salt", 1) {}
};
class Pepper : public Addble {
public:
    Pepper() : Addble("Pepper", 2) {}
};


class Pizza : public IPrintble {
private:
    string name;
    unsigned short diameter;
    vector<Ingridient> ingridients;
    vector<Addble> addbles;
    unsigned short pizzaPrice = 0;
    unsigned int totalPrice = 0;
public:
    Pizza(string n, unsigned short d, vector<Ingridient> productList, unsigned short price) {
        this->name = n;
        this->diameter = d;
        this->ingridients = productList;
        this->pizzaPrice = price;
    }
    friend void addMore(Addble i, Pizza *p);
    friend void removeMore(Addble i, Pizza *p);
    string printIt() override {
        string out = "Pizza name: " + this->name + '\t' + "Diameter: " + to_string(this->diameter) + '\n' + "Ingridients: " + '\n';
        for (Ingridient i : ingridients) {
            out += '\t' + i.printIt() + '\n';
        }
        for (Addble i : addbles) {
            out += '\t' + i.printIt() + '\n';
        }

        int addblesPrice = 0;
        for (Addble i : addbles) {
            addblesPrice += i.getCount() * i.getPrice();
        }
        this->totalPrice = pizzaPrice + addblesPrice;
        this->totalPrice *= this->diameter * 0.11;
        out += "Total cost: " + to_string(this->totalPrice);
        return out;
    }
    int getTotalPrice() {return this->totalPrice;}
};

class Motcarella : public Pizza {
public:
    const static int price = 150;
    explicit Motcarella(unsigned short d) : Pizza("Mocarella", d, {Parmezan(), Peperoni(), Olive(), Pickle()}, price) {};
};
class FourCheeses : public Pizza {
public:
    const static int price = 320;
    explicit FourCheeses(unsigned short d) : Pizza("FourCheeses", d, {Parmezan(), Tomato(), Olive(), Jalapeno()}, price) {};
};
class Chickened : public Pizza {
public:
    const static int price = 270;
    explicit Chickened(unsigned short d) : Pizza("Chickened", d, {Tomato(), Olive(), Jalapeno(), Chiken()}, price) {};
};
class SeaFooded : public Pizza {
public:
    const static int price = 430;
    explicit SeaFooded(unsigned short d) : Pizza("SeaFooded", d, {Tomato(), Olive(), Jalapeno(), Seafood()}, price) {};
};


void addMore(Addble i, Pizza *p) {
    for (Addble &j : (*p).addbles) {
        if (j.getName() == i.getName()) {
            j.add();
            return;
        }
    }
    (*p).addbles.emplace_back(i);
}
void removeMore(Addble i, Pizza *p) {
    for (Addble &j : (*p).addbles) {
        if (j.getName() == i.getName()) {
            j.remove();
            break;
        }
    }
}

void printControl() {
    cout << "1. to add Pizza from list" << endl
    << "2. to remove Pizza from cart" << endl
    << "3. to print cart" << endl;
}

bool checkFail() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    return false;
}

void addAddble(Pizza &pizza) {
    int temp;
    while (true) {
        system("cls");
        cout << "What u would to add?" << endl << "1. Chees" << endl << "2. Salt" << endl << "3. Pepper" << endl << "4. All right" << endl;
        cin >> temp;
        if (checkFail()) continue;
        switch (temp) {
            case 1:
                addMore(Chees(), &pizza);
                break;
            case 2:
                addMore(Salt(), &pizza);
                break;
            case 3:
                addMore(Pepper(), &pizza);
                break;
            case 4:
                return;
        }
    }
}

void Adding(vector<Pizza> *cart) {
    int temp;
    bool flag = true;
    while (flag) {
        system("cls");
        cout << "1. to add Motcarella(150$)" << endl
             << "2. to add FourCheeses(320$)" << endl
             << "3. to add Chickened(270$)" << endl
             << "4. to add SeaFooded(430$)" << endl
             << "5. to end adding" << endl;
        try {
            cin >> temp;
        } catch (std::exception &e) {
            cout << "Error" << endl;
            continue;
        }
        int pizzaSize = 0;
        switch (temp) {
            case 1:
                while (true) {
                    cout << "Pizza size? ";
                    cin >> pizzaSize;
                    if (checkFail()) continue;
                    cout << "Would to add some additition? 1-Yes 0-No\n";
                    cin >> temp;
                    if (checkFail()) continue;
                    Pizza pizza = Motcarella(pizzaSize);
                    if (temp) addAddble(pizza);
                    cart->emplace_back(pizza);
                    break;
                }
                break;
            case 2:
                while (true) {
                    cout << "Pizza size? ";
                    cin >> pizzaSize;
                    if (checkFail()) continue;
                    cout << "Would to add some additition? 1-Yes 0-No\n";
                    cin >> temp;
                    if (checkFail()) continue;
                    Pizza pizza = FourCheeses(pizzaSize);
                    if (temp) addAddble(pizza);
                    cart->emplace_back(pizza);
                    break;
                }
                break;
            case 3:
                while (true) {
                    cout << "Pizza size? ";
                    cin >> pizzaSize;
                    if (checkFail()) continue;
                    cout << "Would to add some additition? 1-Yes 0-No\n";
                    cin >> temp;
                    if (checkFail()) continue;
                    Pizza pizza = Chickened(pizzaSize);
                    if (temp) addAddble(pizza);
                    cart->emplace_back(pizza);
                    break;
                }
                break;
            case 4:
                while (true) {
                    cout << "Pizza size? ";
                    cin >> pizzaSize;
                    if (checkFail()) continue;
                    cout << "Would to add some additition? 1-Yes 0-No\n";
                    cin >> temp;
                    if (checkFail()) continue;
                    Pizza pizza = SeaFooded(pizzaSize);
                    if (temp) addAddble(pizza);
                    cart->emplace_back(pizza);
                    break;
                }
                break;
            case 5:
                flag = false;
                break;
        }
    }
}

void Removing(vector<Pizza> *cart) {
    int temp;
    while (true) {
        cout << "Enter pizza index that need to remove from cart or -1 to back\n";
        cin >> temp;
        if (checkFail()) continue;
        if (temp == -1) return;
        if (temp >= 0 && temp < cart->size()) {
            cart->erase(next(cart->begin(), temp));
            break;
        }
    }
}

void PrintCart(vector<Pizza> *cart) {
    system("cls");
    int sum = 0;
    for (auto & i : *cart) {
        cout << i.printIt() << endl;
        sum += i.getTotalPrice();
    }
    cout << "\nSUM IS " << sum << "\n\nPress button in atomic case to return menu" << endl;
    int voidVar;
    cin >> voidVar;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    vector<Pizza> *cart = new vector<Pizza>;
    int temp;
    while (true) {
        system("cls");
        printControl();
        cin >> temp;
        if (checkFail()) continue;
        switch (temp) {
            case 1:
                Adding(cart);
                break;
            case 2:
                Removing(cart);
                break;
            case 3:
                PrintCart(cart);
                break;
        }
    }
}
