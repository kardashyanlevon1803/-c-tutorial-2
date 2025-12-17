#include <stdio.h>
#include <math.h>

double f(double x) {
    return 3.0 * sqrt(x);
}

double exact(double a, double b) {
    return 2.0 * (pow(b, 1.5) - pow(a, 1.5));
}

double rect_left(double a, double b, double e) {
    int n = 1;
    double h, s1, s2;
    s1 = 0;
    do {
        n *= 2;
        h = (b - a) / n;
        s2 = 0;
        for (int i = 0; i < n; i++)
            s2 += f(a + i * h);
        s2 *= h;
        if (fabs(s2 - s1) < e) break;
        s1 = s2;
    } while (1);
    return s2;
}

double rect_right(double a, double b, double e) {
    int n = 1;
    double h, s1 = 0, s2;
    do {
        n *= 2;
        h = (b - a) / n;
        s2 = 0;
        for (int i = 1; i <= n; i++)
            s2 += f(a + i * h);
        s2 *= h;
        if (fabs(s2 - s1) < e) break;
        s1 = s2;
    } while (1);
    return s2;
}

double rect_mid(double a, double b, double e) {
    int n = 1;
    double h, s1 = 0, s2;
    do {
        n *= 2;
        h = (b - a) / n;
        s2 = 0;
        for (int i = 0; i < n; i++)
            s2 += f(a + (i + 0.5) * h);
        s2 *= h;
        if (fabs(s2 - s1) < e) break;
        s1 = s2;
    } while (1);
    return s2;
}

double trapezoid(double a, double b, double e) {
    int n = 1;
    double h, s1 = 0, s2;
    do {
        n *= 2;
        h = (b - a) / n;
        s2 = 0.5 * (f(a) + f(b));
        for (int i = 1; i < n; i++)
            s2 += f(a + i * h);
        s2 *= h;
        if (fabs(s2 - s1) < e) break;
        s1 = s2;
    } while (1);
    return s2;
}

double simpson(double a, double b, double e) {
    int n = 2;
    double h, s1 = 0, s2;
    do {
        n *= 2;
        h = (b - a) / n;
        s2 = f(a) + f(b);
        for (int i = 1; i < n; i++)
            s2 += f(a + i * h) * (i % 2 ? 4 : 2);
        s2 *= h / 3;
        if (fabs(s2 - s1) < e) break;
        s1 = s2;
    } while (1);
    return s2;
}

int main(void) {
    double a = 2.0, b = 9.0, e = 1e-4;
    printf("%.6f\n", rect_left(a, b, e));
    printf("%.6f\n", rect_right(a, b, e));
    printf("%.6f\n", rect_mid(a, b, e));
    printf("%.6f\n", trapezoid(a, b, e));
    printf("%.6f\n", simpson(a, b, e));
    printf("%.6f\n", exact(a, b));
    return 0;
}
