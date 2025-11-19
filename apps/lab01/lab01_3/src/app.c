#include "app.h"

// Variant 26
// e^(a * |1 - 2*cos(b*x)|)
// a = 7.23, b = 3.43, x = 5.22

int main()
{
	double a = 7.23, b = 3.43, x = 5.22;

    double t = fabs(1 - 2 * cos(b * x));

    double result = exp(a * t);

    printf("e^(a * |1 - 2*cos(b*x)|) = %.6f\n", result);

    return 0;
}