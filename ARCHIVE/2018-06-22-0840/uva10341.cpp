#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

int p, q, r, s, t, u;

double func (double x) {
	return p*exp(-x) + q*sin (x) + r*cos (x) + s*tan(x) + t*(x*x)+u;
}

double bb_c (double l, double r) {
	if (cmp(l, r) >= 0) return l;
	double mid = (l+r)/2;
	if (func (mid) > 0)
		return bb_c (l, mid-EPS);
	else
		return bb_c (mid, r);
}

double bb_d (double l, double r) {
	if (cmp(l, r) >= 0) return l;
	double mid = (l+r) / 2;
	if (func (mid) < 0)
		return bb_d (l, mid-EPS);
	else
		return bb_d (mid, r);
}

int main ()
{
	while (scanf ("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
		// printf ("%0.10lf\n", func(0.0));
		// printf ("%0.10lf\n", func(1.0));
		if (cmp (func (0.0), func (1.0)) == 1) {
			// Decrescente
			if (func(0.0)+EPS < 0 || func(1.0)-EPS > 0)
				printf ("No solution\n");
			else
				printf ("%0.4lf\n", bb_d (0.0, 1.0));
		} else {
			// Crescente
			if (func(0.0)-EPS > 0 || func(1.0)+EPS < 0)
				printf ("No solution\n");
			else
				printf ("%0.4lf\n", bb_c (0.0, 1.0));
		}
	}

	return 0;
}
