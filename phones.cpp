#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

struct Phone {
    string model;
    int year;
    int ram;
    int storage;
    double price;
};

int main() {
    vector<Phone> phones = {
        {"Samsung Galaxy S23", 2023, 8, 128, 999.99},
        {"iPhone 14", 2022, 6, 256, 1099.99},
        {"Xiaomi 13", 2023, 12, 256, 699.99},
        {"Google Pixel 7", 2022, 8, 128, 599.99},
        {"OnePlus 11", 2023, 16, 256, 799.99}
    };

    double total = accumulate(phones.begin(), phones.end(), 0.0,
        [](double sum, const Phone& p) { return sum + p.price; });
    cout << "Average price: " << total / phones.size() << "$" << endl;

    auto maxStorage = max_element(phones.begin(), phones.end(),
        [](const Phone& a, const Phone& b) { return a.storage < b.storage; });
    cout << "Max storage: " << maxStorage->model << " (" << maxStorage->storage << "GB)" << endl;

    double minPrice = 600.0, maxPrice = 900.0;
    cout << "Phones in range " << minPrice << "$ - " << maxPrice << "$:" << endl;
    for_each(phones.begin(), phones.end(), [minPrice, maxPrice](const Phone& p) {
        if (p.price >= minPrice && p.price <= maxPrice)
            cout << "  " << p.model << " - " << p.price << "$" << endl;
    });

    int year = 2023;
    int cnt = count_if(phones.begin(), phones.end(),
        [year](const Phone& p) { return p.year == year; });
    cout << "Phones released in " << year << ": " << cnt << endl;

    return 0;
}