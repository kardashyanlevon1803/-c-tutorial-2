#include <iostream>
using namespace std;

template <typename T>
class SharedPtr {
    T* ptr;
    int* count;

public:
    SharedPtr() {
        ptr = nullptr;
        count = new int(0);
    }

    SharedPtr(T* p) {
        ptr = p;
        count = new int(1);
    }

    SharedPtr(const SharedPtr& other) {
        ptr = other.ptr;
        count = other.count;
        (*count)++;
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (this == &other) {
            return *this;
        }

        (*count)--;
        if (*count == 0) {
            delete ptr;
            delete count;
        }

        ptr = other.ptr;
        count = other.count;
        (*count)++;

        return *this;
    }

    T& operator*() {
        return *ptr;
    }

    T* operator->() {
        return ptr;
    }

    int getCount() {
        return *count;
    }

    bool isNull() {
        return ptr == nullptr;
    }

    ~SharedPtr() {
        (*count)--;
        if (*count == 0) {
            delete ptr;
            delete count;
        }
    }
};

struct Person {
    string name;
    int age;

    Person(string n, int a) {
        name = n;
        age = a;
    }

    void print() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    cout << "=== int ===" << endl;
    SharedPtr<int> p1(new int(42));
    cout << "Value: " << *p1 << endl;
    cout << "Count: " << p1.getCount() << endl;

    SharedPtr<int> p2 = p1;
    cout << "After copy - Count: " << p1.getCount() << endl;

    SharedPtr<int> p3;
    p3 = p1;
    cout << "After assign - Count: " << p1.getCount() << endl;

    *p1 = 100;
    cout << "p1: " << *p1 << endl;
    cout << "p2: " << *p2 << endl;
    cout << "p3: " << *p3 << endl;

    cout << endl << "=== Person ===" << endl;
    SharedPtr<Person> sp1(new Person("Alice", 20));
    sp1->print();
    cout << "Count: " << sp1.getCount() << endl;

    SharedPtr<Person> sp2 = sp1;
    cout << "After copy - Count: " << sp1.getCount() << endl;
    sp2->print();

    return 0;
}