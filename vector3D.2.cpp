#include <iostream>
#include <cmath>
using namespace std;

class Vector3D {
private:
    double x;
    double y;
    double z;

public:
    Vector3D(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

    Vector3D operator+(Vector3D other) {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D operator-(Vector3D other) {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    Vector3D operator*(double scalar) {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }

    bool operator==(Vector3D other) {
        return x == other.x && y == other.y && z == other.z;
    }

    double& operator[](int index) {
        if (index == 0) return x;
        if (index == 1) return y;
        return z;
    }

    double length() {
        return sqrt(x * x + y * y + z * z);
    }

    void print() {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

int main() {
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);

    cout << "Vector 1: ";
    v1.print();
    cout << "Vector 2: ";
    v2.print();

    Vector3D sum = v1 + v2;
    cout << "v1 + v2: ";
    sum.print();

    Vector3D diff = v1 - v2;
    cout << "v1 - v2: ";
    diff.print();

    Vector3D scaled = v1 * 3.0;
    cout << "v1 * 3: ";
    scaled.print();

    cout << "v1 == v2: " << (v1 == v2 ? "true" : "false") << endl;

    cout << "v1[0] = " << v1[0] << endl;
    cout << "v1[1] = " << v1[1] << endl;
    cout << "v1[2] = " << v1[2] << endl;

    v1[0] = 10.0;
    cout << "v1 after v1[0] = 10: ";
    v1.print();

    return 0;
}