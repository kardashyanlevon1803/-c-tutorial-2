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

    double getX() {
        return x;
    }

    double getY() {
        return y;
    }

    double getZ() {
        return z;
    }

    void setX(double x) {
        this->x = x;
    }

    void setY(double y) {
        this->y = y;
    }

    void setZ(double z) {
        this->z = z;
    }

    double dot(Vector3D other) {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3D cross(Vector3D other) {
        double cx = y * other.z - z * other.y;
        double cy = z * other.x - x * other.z;
        double cz = x * other.y - y * other.x;
        return Vector3D(cx, cy, cz);
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

    cout << "Dot product: " << v1.dot(v2) << endl;

    Vector3D v3 = v1.cross(v2);
    cout << "Cross product: ";
    v3.print();

    cout << "Length of vector 1: " << v1.length() << endl;
    cout << "Length of vector 2: " << v2.length() << endl;

    return 0;
}