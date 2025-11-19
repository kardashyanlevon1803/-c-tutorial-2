#include "app.h"

/*
  x^(a*x)
  --------
  e^(-a*x)
*/

int main()
{
	double a, b, x;

	printf("Enter a, b, x:");

	int ret = scanf("%lf %lf %lf", &a, &b, &x);

	if (ret != 3)
	{
		printf("Error! Cannot read 3 arguments but only %d\n", ret);
		return -1;
	}

	printf("\n");

	double t1 = pow(x, a * x);

	double t2 = exp(-a * x);

	double result = t1 / t2;

	printf("x^(%.3f*%.3f)\n------------------------ = %.3f", a, x, result);
	
	printf("\ne^(-%.3f*%.3f)", a, x);

	return 0;
}