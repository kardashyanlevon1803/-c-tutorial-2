#include <iostream>
#include <vector>
using namespace std;

class DiagonalMatrix {
private:
    int size;
    vector<double> diagonal;

public:
    DiagonalMatrix(int n) {
        size = n;
        diagonal.resize(n, 0);
    }

    void setValue(int index, double value) {
        if (index >= 0 && index < size) {
            diagonal[index] = value;
        } else {
            cout << "Index out of range!" << endl;
        }
    }

    double getValue(int index) {
        if (index >= 0 && index < size) {
            return diagonal[index];
        }
        cout << "Index out of range!" << endl;
        return 0;
    }

    int getSize() {
        return size;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j) {
                    cout << diagonal[i] << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    void multiply(double scalar) {
        for (int i = 0; i < size; i++) {
            diagonal[i] *= scalar;
        }
    }
};

int main() {
    DiagonalMatrix m(4);

    m.setValue(0, 5);
    m.setValue(1, 3);
    m.setValue(2, 7);
    m.setValue(3, 2);

    cout << "Diagonal matrix:" << endl;
    m.print();

    m.multiply(2);
    cout << "After multiplying by 2:" << endl;
    m.print();

    cout << "Element at index 1: " << m.getValue(1) << endl;

    return 0;
}