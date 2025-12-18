#include <stdio.h>
#include <math.h>

int main() {
    double a, x, y;
    scanf("%lf %lf", &a, &x);
    y = pow(x, a * x) / exp(-a * x);
    printf("%lf", y);
    return 0;
}
