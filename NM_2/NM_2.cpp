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
	return F(((a + b) / 2) + (((b - a) / 2) * t));
}

double TrapezeMethod(double a, double b, double n)
{
	double h = (b - a) / n;

	double result = h / 2 * (F(a) + F(b));

	for (int i = 1; i < n; i++)
	{
		result += (F(a + h * i) * h);
	}

	return result;
}

double GaussMethod(double a, double b, double n)
{
	double result = 0.0;

	double t[4] = { -0.8611363, -0.3399810, 0.3399810, 0.8611363 };
	double A[4] = { 0.3478548, 0.6521451, 0.6521451, 0.3478548 };

	for (int i = 0; i < n; i++)
	{
		result += A[i] * ((b - a) / 2) * GaussF(t[i], a, b);
		cout << "result = " << result << endl;
	}

	return result;
}