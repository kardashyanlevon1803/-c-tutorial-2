#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct MyStruct {
    int a;
    float b;
    double c;
};

int main() {
    srand(time(0));

    MyStruct structs[3];

    for (int i = 0; i < 3; i++) {
        structs[i].a = rand() % 100;
        structs[i].b = (float)(rand() % 1000) / 10.0;
        structs[i].c = (double)(rand() % 10000) / 100.0;
    }

    for (int i = 0; i < 3; i++) {
        cout << "a=" << structs[i].a << " b=" << structs[i].b << " c=" << structs[i].c << endl;
    }

    return 0;
}