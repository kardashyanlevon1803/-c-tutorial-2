#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    string name;
    string subject;

public:
    Teacher(string name, string subject) {
        this->name = name;
        this->subject = subject;
    }

    string getName() {
        return name;
    }

    string getSubject() {
        return subject;
    }

    void setName(string name) {
        this->name = name;
    }

    void setSubject(string subject) {
        this->subject = subject;
    }

    void print() {
        cout << "Teacher: " << name << ", Subject: " << subject << endl;
    }
};

class Student {
private:
    string name;
    int age;
    Teacher* mentor;

public:
    Student(string name, int age) {
        this->name = name;
        this->age = age;
        mentor = nullptr;
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

    void setMentor(Teacher* teacher) {
        mentor = teacher;
    }

    Teacher* getMentor() {
        return mentor;
    }

    void print() {
        cout << "Student: " << name << ", Age: " << age << endl;
        if (mentor != nullptr) {
            cout << "Mentor: " << mentor->getName() << ", Subject: " << mentor->getSubject() << endl;
        } else {
            cout << "No mentor" << endl;
        }
    }
};

int main() {
    Teacher t1("Sergiy Puziryov", "Programming");
    Student s1("Levon Kardashyan", 19);

    s1.setMentor(&t1);

    cout << "Student info:" << endl;
    s1.print();

    cout << endl;

    cout << "Teacher info:" << endl;
    t1.print();

    return 0;
}