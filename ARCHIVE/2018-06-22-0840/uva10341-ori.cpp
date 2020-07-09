#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const double EPS = 1e-9;

int p, q, r, s, t, u;

double func (double x) {
	return p*exp(-x) + q*sin (x) + r*cos (x) + s*tan(x) + t*(x*x)+u;
}

double bb_c (double l, double r) {
	if (l+EPS > r) return l;
	double mid = (l+r)/2;
	if (func (mid) > 0)
		return bb_c (l, mid-EPS);
	else
		return bb_c (mid, r);
}

double bb_d (double l, double r) {
	if (l+EPS > r) return l;
	double mid = (l+r) / 2;
	if (func (mid) < 0)
		return bb_d (l, mid-EPS);
	else
		return bb_d (mid, r);
}

int main ()
{
	while (scanf ("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
		if (func (0.0) > func (1.0)) {
			// Decrescente
			if (func (1.0) > 0 || func(0.0) < 0)
				printf ("No solution\n");
			else
				printf ("%0.4lf\n", bb_d (0.0, 1.0));
		} else {
			// Crescente
			if (func(0.0) > 0 || func(1.0) < 0)
				printf ("No solution\n");
			else
				printf ("%0.4lf\n", bb_c (0.0, 1.0));
		}
	}

	return 0;
}
