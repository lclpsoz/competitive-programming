#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int p, q, r, s, t, u;

double func (double x) {
	return p*exp(-x) + q*sin (x) + r*cos (x) + s*tan(x) + t*(x*x)+u;
}

double bb_c (double l, double r) {
	if (l+0.0000001 > r) return l;
	double mid = (l+r)/2.0;
	if (func (mid) > 0)
		return bb_c (l, mid-0.0000001);
	else
		return bb_c (mid, r);
}

int main ()
{
	while (scanf ("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
		printf ("%0.4lf\n", bb_c (0.0, 1.0));
	}

	return 0;
}
