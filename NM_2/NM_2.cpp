#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

double TrapezeMethod(double a, double b, double e, double n);
double F(double x);

using namespace std;


int main()
{
	cout.precision(6);
	double epsilone = 10e-5;
	double maximumDif2F = 0.179587;
	cout << "Integral F(x) = " << TrapezeMethod(0, M_PI, epsilone, 3000);
}

double F(double x)
{
	if (x == 0) return 0.0;
	return sin(x) / sqrt(x);
}



double TrapezeMethod(double a, double b, double e, double n)
{
	double h = (b - a) / n;

	//cout << "h = " << h << endl;

	double s = h / 2 * (F(a) + F(b));
	double r = -n * pow(h, 3) / 12 * 0.5;

	//cout << "s0 = " << s << '\n';

	for (int i = 1; i < n; i++)
	{
		s += (F(a + h * i) * h);
		//cout << "s" << i << " = " << s << '\n';
	}

	cout << "R = " << r << endl;

	return s;
}

double GaussMethod(double a, double b, double e, double n)
{

}