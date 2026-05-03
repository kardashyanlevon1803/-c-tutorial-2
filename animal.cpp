#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;

public:
    Animal(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    virtual void sound() = 0;
};

class Dog : public Animal {
public:
    Dog(string name) : Animal(name) {}

    void sound() {
        cout << name << " says: Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string name) : Animal(name) {}

    void sound() {
        cout << name << " says: Meow!" << endl;
    }
};

class Cow : public Animal {
public:
    Cow(string name) : Animal(name) {}

    void sound() {
        cout << name << " says: Moo!" << endl;
    }
};

int main() {
    Dog d("Rex");
    Cat c("Whiskers");
    Cow cow("Bessie");

    d.sound();
    c.sound();
    cow.sound();

    return 0;
}