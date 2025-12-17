#include <stdio.h>
#include <math.h>

double f(double x) {
    return -log(2 * sin(x / 2));
}

int main(void) {
    double a = M_PI / 5.0;
    double b = 9 * M_PI / 5.0;
    double h = 0.2;
    FILE *fp = fopen("result.txt", "w");

    double x_prev = a;
    double y_prev = f(x_prev);
    double integral = 0.0;

    fprintf(fp, "x\t\t y\n");

    for (double x = a; x <= b + 1e-9; x += h) {
        double y = f(x);
        fprintf(fp, "%.6f\t %.6f", x, y);

        if (x > a) {
            integral += y_prev * h;
            if ((y_prev > y) && (y_prev > f(x_prev - h)))
                fprintf(fp, "\tMax");
            if ((y_prev < y) && (y_prev < f(x_prev - h)))
                fprintf(fp, "\tMin");
        }

        fprintf(fp, "\n");
        x_prev = x;
        y_prev = y;
    }

    fprintf(fp, "\nIntegral [%.3f, %.3f] = %.6f\n", a, b, integral);

    fclose(fp);
    return 0;
}
