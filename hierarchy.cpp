#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    int age;

public:
    Animal(string name, int age) {
        this->name = name;
        this->age = age;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    void setName(string name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    void print() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Bird : public Animal {
private:
    double wingspan;

public:
    Bird(string name, int age, double wingspan) : Animal(name, age) {
        this->wingspan = wingspan;
    }

    double getWingspan() {
        return wingspan;
    }

    void setWingspan(double wingspan) {
        this->wingspan = wingspan;
    }

    void print() {
        cout << "Bird - Name: " << name << ", Age: " << age << ", Wingspan: " << wingspan << " m" << endl;
    }
};

class Human : public Animal {
private:
    string profession;

public:
    Human(string name, int age, string profession) : Animal(name, age) {
        this->profession = profession;
    }

    string getProfession() {
        return profession;
    }

    void setProfession(string profession) {
        this->profession = profession;
    }

    void print() {
        cout << "Human - Name: " << name << ", Age: " << age << ", Profession: " << profession << endl;
    }
};

int main() {
    Animal a("Dog", 10);
    Bird b("Eagle", 3, 2.5);
    Human h("Levon Kardashyan", 19, "Student");

    cout << "Animal info:" << endl;
    a.print();

    cout << "Bird info:" << endl;
    b.print();

    cout << "Human info:" << endl;
    h.print();

    return 0;
}