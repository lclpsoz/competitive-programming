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

int n;

int main ()
{
	scanf ("%d", &n);
	if (n >= 0)
		printf ("%d\n", n);
	else {
		if (n < -10) {
			int a, b;
			a = b = n;
			b /= 100;
			b = -(abs(b)*10);
			b += -(abs(a)%10);
			a /= 10;
			// printf ("%d %d\n", a, b);
			printf ("%d\n", max (a, b));
		} else
			printf ("0\n");
	}

	return 0;
}
