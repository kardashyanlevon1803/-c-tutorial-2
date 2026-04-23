#include <iostream>
#include <string>

using namespace std;

struct Car {
    string brand;
    int year;
    double engine;
    double price;
};

ostream& operator<<(ostream& out, const Car& c) {
    out << "Brand: " << c.brand << endl;
    out << "Year: " << c.year << endl;
    out << "Engine: " << c.engine << " L" << endl;
    out << "Price: " << c.price << " UAH" << endl;
    return out;
}

istream& operator>>(istream& in, Car& c) {
    in >> c.brand >> c.year >> c.engine >> c.price;
    return in;
}

Car operator+(const Car& c, double amount) {
    Car result = c;
    result.price += amount;
    return result;
}

Car operator*(const Car& c, double factor) {
    Car result = c;
    result.price *= factor;
    return result;
}

int main() {
    Car car1 = {"BMW", 2017, 3.0, 900000};

    cout << "=== Car ===" << endl;
    cout << car1;

    cout << "=== Price + 50000 ===" << endl;
    Car car2 = car1 + 50000;
    cout << car2;

    cout << "=== Price * 1.1 ===" << endl;
    Car car3 = car1 * 1.1;
    cout << car3;

    return 0;
}