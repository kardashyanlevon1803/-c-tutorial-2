#include <iostream>
#include <cmath>
using namespace std;

class Point3D {
private:
    double x;
    double y;
    double z;

public:
    Point3D(double x, double y, double z) {
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

    double distance(Point3D other) {
        double dx = x - other.x;
        double dy = y - other.y;
        double dz = z - other.z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }

    void print() {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

int main() {
    Point3D p1(1.0, 2.0, 3.0);
    Point3D p2(4.0, 6.0, 8.0);

    cout << "Point 1: ";
    p1.print();
    cout << "Point 2: ";
    p2.print();

    cout << "Distance: " << p1.distance(p2) << endl;

    p1.setX(0.0);
    p1.setY(0.0);
    p1.setZ(0.0);

    cout << "Point 1 after change: ";
    p1.print();
    cout << "Distance: " << p1.distance(p2) << endl;

    return 0;
}