#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector<vector<double>> data;

public:
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        data.resize(rows, vector<double>(cols, 0));
    }

    int getRows() { return rows; }
    int getCols() { return cols; }

    double& operator()(int i, int j) {
        return data[i][j];
    }

    Matrix operator+(Matrix other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result(i, j) = data[i][j] + other(i, j);
        return result;
    }

    Matrix operator-(Matrix other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result(i, j) = data[i][j] - other(i, j);
        return result;
    }

    Matrix operator*(Matrix other) {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    result(i, j) += data[i][k] * other(k, j);
        return result;
    }

    Matrix operator*(double scalar) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result(i, j) = data[i][j] * scalar;
        return result;
    }

    bool operator==(Matrix other) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (data[i][j] != other(i, j))
                    return false;
        return true;
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Matrix m1(2, 2);
    m1(0, 0) = 1; m1(0, 1) = 2;
    m1(1, 0) = 3; m1(1, 1) = 4;

    Matrix m2(2, 2);
    m2(0, 0) = 5; m2(0, 1) = 6;
    m2(1, 0) = 7; m2(1, 1) = 8;

    cout << "Matrix 1:" << endl;
    m1.print();

    cout << "Matrix 2:" << endl;
    m2.print();

    Matrix sum = m1 + m2;
    cout << "m1 + m2:" << endl;
    sum.print();

    Matrix diff = m1 - m2;
    cout << "m1 - m2:" << endl;
    diff.print();

    Matrix prod = m1 * m2;
    cout << "m1 * m2:" << endl;
    prod.print();

    Matrix scaled = m1 * 2.0;
    cout << "m1 * 2:" << endl;
    scaled.print();

    cout << "m1 == m2: " << (m1 == m2 ? "true" : "false") << endl;

    cout << "m1(0,0) = " << m1(0, 0) << endl;
    cout << "m1(1,1) = " << m1(1, 1) << endl;

    return 0;
}