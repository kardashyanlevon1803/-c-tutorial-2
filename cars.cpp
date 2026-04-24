#include <iostream>
#include <string>
using namespace std;

struct Car {
    string model;
    int speed;
    double price;
};

Car findFastest(Car arr[], int n) {
    Car fastest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i].speed > fastest.speed)
            fastest = arr[i];
    }
    return fastest;
}

Car findMostExpensive(Car arr[], int n) {
    Car expensive = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i].price > expensive.price)
            expensive = arr[i];
    }
    return expensive;
}

int main() {
    Car cars[] = {
        {"BMW M5", 305, 85000.0},
        {"Toyota Camry", 210, 35000.0},
        {"Lamborghini Huracan", 325, 250000.0},
        {"Mercedes C63", 290, 75000.0},
        {"Honda Civic", 200, 25000.0}
    };

    int n = 5;

    Car fastest = findFastest(cars, n);
    cout << "Fastest: " << fastest.model << " - " << fastest.speed << " km/h" << endl;

    Car expensive = findMostExpensive(cars, n);
    cout << "Most expensive: " << expensive.model << " - " << expensive.price << "$" << endl;

    return 0;
}