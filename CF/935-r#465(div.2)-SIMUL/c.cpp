#include <cstdio>
#include <cmath>
using namespace std;

long double ap, x, y;	// Apartment
long double x2, y2;		// Fafa's laptop
long double x3, y3, r;
long double vx, vy;

long double dist (long double a1, long double b1, long double a2, long double b2)
{
	a1 -= a2;
	b1 -= b2;
	a1 *= a1;
	b1 *= b1;
	return sqrt (a1+b1);
}

int main ()
{
	scanf ("%Lf %Lf %Lf %Lf %Lf", &ap, &x, &y, &x2, &y2);
	long double d = dist (x, y, x2, y2);
	if (x == x2 && y == y2) {
		r = ap/2;
		x3 = x;
		y3 = (y+(y+ap))/2;
	} else if (d >= ap) {
		r = ap;
		x3 = x;
		y3 = y;
	} else {
		r = (ap+d)/2;

		vx = x - x2;
		vy = y - y2;
		vx /= d;
		vy /= d;
		vx *= r;
		vy *= r;

		x3 = vx + x2;
		y3 = vy + y2;
	}

	printf ("%.20Lf %.20Lf %.20Lf\n", x3, y3, r);

	return 0;
}
