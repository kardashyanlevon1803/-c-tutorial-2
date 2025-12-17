#include <stdio.h>
#include <math.h>

#define K 7
#define N 20
#define EPS 0.0001

int main() {
    const double PI = 3.141592653589793;

    double a = PI / 5.0;
    double b = 9.0 * PI / 5.0;
    double h = (b - a) / (K - 1);

    double x, exact, sumN, sumEps, term;
    int i, n;

    printf("   x\t\tf(x)\t\tS(N)\t\tS(eps)\n");
    printf("----------------------------------------------------------\n");

    for (i = 0; i < K; i++) {
        x = a + i * h;

        exact = -log(fabs(2.0 * sin(x / 2.0)));

        sumN = 0.0;
        for (n = 1; n <= N; n++) {
            sumN += cos(n * x) / n;
        }

        sumEps = 0.0;
        n = 1;
        do {
            term = cos(n * x) / n;
            sumEps += term;
            n++;    
        } while (fabs(term) >= EPS);

        printf("%8.4f\t%8.4f\t%8.4f\t%8.4f\n",
            x, exact, sumN, sumEps);
    }

    return 0;
}