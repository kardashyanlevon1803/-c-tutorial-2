﻿#include "app.h"

/*
Variant 2
  x^(a*x)
  --------
  e^(-a*x)

  a = -1.44, b = -0.12, x = 1.04
*/

int main()
{
	double a = -1.44, b = -0.12, x = 1.04;

	double t1 = pow(x, a * x);
	double t2 = exp(-a * x);

	double result = t1 / t2;

	printf("x^(%.3f*%.3f)\n------------------------ = %.3f", a, x, result);
	printf("\ne^(-%.3f*%.3f)", a, x);

	return 0;
}