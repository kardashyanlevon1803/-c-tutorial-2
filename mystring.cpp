#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char* data;
    int length;

public:
    MyString(const char* str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    ~MyString() {
        delete[] data;
    }

    int getLength() {
        return length;
    }

    void print() {
        cout << data << endl;
    }

    MyString operator+(MyString other) {
        char* temp = new char[length + other.length + 1];
        strcpy(temp, data);
        strcat(temp, other.data);
        MyString result(temp);
        delete[] temp;
        return result;
    }

    bool operator==(MyString other) {
        return strcmp(data, other.data) == 0;
    }

    bool operator!=(MyString other) {
        return strcmp(data, other.data) != 0;
    }

    char& operator[](int index) {
        return data[index];
    }
};

int main() {
    MyString s1("Hello");
    MyString s2(" World");

    cout << "s1: ";
    s1.print();
    cout << "s2: ";
    s2.print();

    MyString s3 = s1 + s2;
    cout << "s1 + s2: ";
    s3.print();

    cout << "s1 == s2: " << (s1 == s2 ? "true" : "false") << endl;
    cout << "s1 != s2: " << (s1 != s2 ? "true" : "false") << endl;

    MyString s4("Hello");
    cout << "s1 == s4: " << (s1 == s4 ? "true" : "false") << endl;

    cout << "s1[0] = " << s1[0] << endl;
    cout << "s1[1] = " << s1[1] << endl;

    s1[0] = 'h';
    cout << "s1 after s1[0] = h: ";
    s1.print();

    cout << "Length of s3: " << s3.getLength() << endl;

    return 0;
}