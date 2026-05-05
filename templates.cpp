#include <iostream>
using namespace std;

template <typename T>
T findMin(T arr[], int n) {
    T min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

template <typename T>
T findMax(T arr[], int n) {
    T max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

template <typename T>
void sortArray(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int a[] = {5, 3, 8, 1, 9, 2};
    int n = 6;

    sortArray(a, n);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Min: " << findMin(a, n) << endl;
    cout << "Max: " << findMax(a, n) << endl;

    double b[] = {3.14, 1.41, 2.71, 0.57};
    int m = 4;

    sortArray(b, m);

    cout << "Sorted: ";
    for (int i = 0; i < m; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    cout << "Min: " << findMin(b, m) << endl;
    cout << "Max: " << findMax(b, m) << endl;

    return 0;
}