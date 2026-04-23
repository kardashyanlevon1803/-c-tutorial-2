#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    if (x <= -2)
        return x * x - 1;
    else if (x <= 2)
        return x * exp(-x * x);
    else
        return x * x * x - x + 1;
}

int main() {
    cout << fixed << setprecision(4);

    cout << "=== Завдання 1: f(x) на [-3, 3], крок 0.1 ===\n";
    cout << setw(8) << "x" << setw(12) << "f(x)" << "\n";
    cout << string(20, '-') << "\n";
    for (double x = -3.0; x <= 3.0 + 1e-9; x += 0.1) {
        cout << setw(8) << x << setw(12) << f(x) << "\n";
    }

    cout << "\n=== Завдання 2: z = xy(x-y) на [-2, 2] x [-2, 2], крок 0.1 ===\n";
    cout << setw(6) << "x" << setw(6) << "y" << setw(12) << "z=xy(x-y)" << "\n";
    cout << string(24, '-') << "\n";
    for (double x = -2.0; x <= 2.0 + 1e-9; x += 0.1) {
        for (double y = -2.0; y <= 2.0 + 1e-9; y += 0.1) {
            double z = x * y * (x - y);
            cout << setw(6) << x << setw(6) << y << setw(12) << z << "\n";
        }
    }

    return 0;
}