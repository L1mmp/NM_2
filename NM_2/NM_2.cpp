#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

double TrapezeMethod(double a, double b, double n);
double GaussMethod(double a, double b, double n);
double F(double x);
double GaussF(double t, double a, double b);

using namespace std;


int main()
{
	cout.precision(6);

	const double epsilone = 10e-5;
	const double maximumDif2F = 0.179587;

	cout << "Integral F(x) = " << TrapezeMethod(0, M_PI, 2800) << '\n';
	cout << "Integral F(x) = " << GaussMethod(0, M_PI, 4) << '\n';
}

double F(double x)
{
	if (x == 0) return 0;
	return sin(x) / sqrt(x);
}

double GaussF(double t, double a, double b)
{
	cout << (b - a / 2) * F((a + b / 2) + (b - a / 2) * t) << endl;
	return (b - a / 2) * F((a + b / 2) + (b - a / 2) * t);
}



double TrapezeMethod(double a, double b, double n)
{
	double h = (b - a) / n;

	double s = h / 2 * (F(a) + F(b));

	for (int i = 1; i < n; i++)
	{
		s += (F(a + h * i) * h);
	}

	return s;
}

double GaussMethod(double a, double b, double n)
{
	double s = 0;

	double t[3] = { -0.774596669, 0.0, 0.774596669 };
	double A[3] = { 0.555555556, 0.888888889, 0.555555556 };

	for (int i = 0; i < n - 1; i++)
	{
		s += A[i] * GaussF(t[i], a, b);
	}

	return s;
}