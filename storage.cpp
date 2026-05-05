#include <iostream>
using namespace std;

template <typename T, int SIZE>
class StaticArray {
    T arr[SIZE];
    int n;

public:
    StaticArray() {
        n = 0;
    }

    void add(T val) {
        if (n < SIZE) {
            arr[n] = val;
            n++;
        } else {
            cout << "Array is full!" << endl;
        }
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int size() {
        return n;
    }
};

template <typename T>
class DynamicArray {
    T* arr;
    int n;

public:
    DynamicArray() {
        arr = nullptr;
        n = 0;
    }

    void add(T val) {
        T* temp = new T[n + 1];
        for (int i = 0; i < n; i++) {
            temp[i] = arr[i];
        }
        temp[n] = val;
        delete[] arr;
        arr = temp;
        n++;
    }

    void remove(int index) {
        T* temp = new T[n - 1];
        for (int i = 0, j = 0; i < n; i++) {
            if (i != index) {
                temp[j] = arr[i];
                j++;
            }
        }
        delete[] arr;
        arr = temp;
        n--;
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int size() {
        return n;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    cout << "=== Static array (int) ===" << endl;
    StaticArray<int, 5> sa;
    sa.add(10);
    sa.add(20);
    sa.add(30);
    sa.add(40);
    sa.add(50);
    sa.add(60);
    sa.print();

    cout << "=== Static array (double) ===" << endl;
    StaticArray<double, 3> sa2;
    sa2.add(1.1);
    sa2.add(2.2);
    sa2.add(3.3);
    sa2.print();

    cout << "=== Dynamic array (int) ===" << endl;
    DynamicArray<int> da;
    da.add(1);
    da.add(2);
    da.add(3);
    da.add(4);
    da.add(5);
    da.print();

    cout << "Remove element at index 2:" << endl;
    da.remove(2);
    da.print();

    cout << "=== Dynamic array (string) ===" << endl;
    DynamicArray<string> da2;
    da2.add("hello");
    da2.add("world");
    da2.add("cpp");
    da2.print();

    return 0;
}