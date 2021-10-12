#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

double TrapezeMethod(double a, double b, double n, double epsiolne);
double GaussMethod(double a, double b, double n);
double GaussMethod(double a, double b, double n, double epsilone);
double F(double x);
double GaussF(double t, double a, double b);

using namespace std;


int main()
{
	cout.precision(6);

	const double epsilone = 1e-6;

	cout << "Integral F(x) = " << TrapezeMethod(0, M_PI, 2, epsilone) << '\n';
	cout << "Integral F(x) = " << GaussMethod(0, M_PI, 4, epsilone) << '\n';
}

double F(double x)
{
	if (x == 0) return 0;
	return sin(x) / sqrt(x);
}

double GaussF(double t, double a, double b)
{
	return F(((a + b) / 2) + (((b - a) / 2) * t));
}

double TrapezeMethod(double a, double b, double n, double epsiolne)
{
	double h1 = (b - a) / n;
	double h2 = (b - a) / (2 * n);

	double I1 = h1 / 2 * (F(a) + F(b));
	double I2 = h2 / 2 * (F(a) + F(b));

	for (int i = 1; i < n; i++)
	{
		I1 += (F(a + h1 * i) * h1);
	}

	for (int i = 1; i < 2 * n; i++)
	{
		I2 += (F(a + h2 * i) * h2);
	}

	cout << "iterations = " << n * 2 << '\n';

	if (abs(I1 - I2) < epsiolne)
	{
		return I2;
	}


	return TrapezeMethod(0, M_PI, n * 2, epsiolne);
}

double GaussMethod(double a, double b, double n)
{
	double result = 0.0;

	double t[4] = { -0.8611363, -0.3399810, 0.3399810, 0.8611363 };
	double A[4] = { 0.3478548, 0.6521451, 0.6521451, 0.3478548 };

	for (int i = 0; i < n; i++)
	{
		result += A[i] * ((b - a) / 2) * GaussF(t[i], a, b);
	}

	return result;
}


double GaussMethod(double a, double b, double n, double epsilone)
{
	double I1 = 0.0;
	double I2 = 0.0;

	int iterations = 2;
	double h = (b - a) / 2;


	I1 = GaussMethod(a, b, 4);
	I2 = GaussMethod(a, b / 2, 4) + GaussMethod(b / 2, b, 4);

	iterations *= 2;
	h /= 2;

	while (abs(I1 - I2) > epsilone)
	{

		I1 = I2;
		I2 = 0.0;

		for (int i = 0; i < iterations; i++)
		{
			I2 += GaussMethod(a + h * i, h * (i + 1), 4);
		}

		h /= 2;
		iterations *= 2;
	}

	return I2;

}