#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return -log(abs(2.0 * sin(x / 2.0)));
}

double S(double x, int N) {
    double sum = 0;
    for (int n = 1; n <= N; n++) {
        sum += cos(n * x) / n;
    }
    return sum;
}

int main() {
    double pi = acos(-1.0);
    int N = 7;
    double a = pi / 5;
    double b = 9 * pi / 5;
    int steps = 10;
    double dx = (b - a) / steps;

    cout << fixed << setprecision(6);
    cout << setw(12) << "x" << setw(14) << "S(x,N=7)" << setw(14) << "f(x)" << setw(14) << "похибка" << "\n";
    cout << string(54, '-') << "\n";

    for (int i = 0; i <= steps; i++) {
        double x = a + i * dx;
        cout << setw(12) << x << setw(14) << S(x, N) << setw(14) << f(x) << setw(14) << abs(S(x, N) - f(x)) << "\n";
    }

    return 0;
}