#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "test.txt";
    string line;

    try {
        ifstream file(filename);

        if (!file.is_open()) {
            throw runtime_error("Cannot open file: " + filename);
        }

        cout << "File contents:" << endl;

        while (getline(file, line)) {
            cout << line << endl;
        }

        if (file.bad()) {
            throw runtime_error("Error while reading file: " + filename);
        }

        file.close();

    } catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}