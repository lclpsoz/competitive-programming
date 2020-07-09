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

int mdc(int a, int b) {
	if(b == 0) return a;
	return mdc(b, a%b);
}
int mmc (int a, int b) { return (a*b) / mdc(a, b); }

int main ()
{
	int a, b, c, d, md, mc;
	int x, y;
	scanf ("%d %d %d %d", &a, &b, &c, &d);

	md = mdc (a, b);
	a /= md; b /= md;
	md = mdc (c, d);
	c /= md; d /= md;

	mc = mmc (a, c);
	x = mc/a; y = mc/c;
	if (b*x < d*y) {
		mc = mmc (b, d);
		x = mc/b; y = mc/d;
		a*=x; c*=y;
		md = mdc (a, c);
		a/=md; c/=md;
		printf ("%d/%d\n", a-c, a);
	} else {
		b*=x; d*=y;
		md = mdc (b, d);
		b/=md; d/=md;
		printf ("%d/%d\n", b-d, b);
	}


	return 0;
}
