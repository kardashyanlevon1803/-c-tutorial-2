#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int getBit(int number, int pos) {
    return (number >> pos) & 1;
}

int setBit(int number, int pos, int onOff) {
    if (onOff == 1)
        return number | (1 << pos);
    else
        return number & ~(1 << pos);
}

void swapXOR(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

string toBinary(int n) {
    string result = "";
    while (n > 0) {
        result = char('0' + n % 2) + result;
        n = n / 2;
    }
    return result;
}

int toDecimal(string bits) {
    int result = 0;
    for (int i = 0; i < bits.size(); i++) {
        result = result * 2 + (bits[i] - '0');
    }
    return result;
}

string encrypt(string text, int key) {
    for (int i = 0; i < text.size(); i++) {
        text[i] = text[i] ^ key;
    }
    return text;
}

int main() {
    system("chcp 65001 > nul");

    cout << "=== 1. Отримання біта ===" << endl;
    int num = 42;
    cout << "Число: " << num << endl;
    cout << "Біт 0 = " << getBit(num, 0) << endl;
    cout << "Біт 1 = " << getBit(num, 1) << endl;
    cout << "Біт 3 = " << getBit(num, 3) << endl;

    cout << "\n=== 2. Вмикання біта ===" << endl;
    int n = 40;
    cout << "Число: " << n << endl;
    n = setBit(n, 0, 1);
    cout << "Увімкнули біт 0: " << n << endl;
    n = setBit(n, 3, 0);
    cout << "Вимкнули біт 3: " << n << endl;

    cout << "\n=== 3. Обмін чисел ===" << endl;
    int a = 5, b = 10;
    cout << "До: a=" << a << " b=" << b << endl;
    swapXOR(a, b);
    cout << "Після: a=" << a << " b=" << b << endl;

    cout << "\n=== 4. Конвертер ===" << endl;
    cout << "42 -> " << toBinary(42) << endl;
    cout << "101010 -> " << toDecimal("101010") << endl;

    cout << "\n=== 5. Шифрування ===" << endl;
    string msg = "Hello";
    int key = 5;
    string enc = encrypt(msg, key);
    string dec = encrypt(enc, key);
    cout << "Оригінал: " << msg << endl;
    cout << "Зашифровано: " << enc << endl;
    cout << "Розшифровано: " << dec << endl;

    return 0;
}