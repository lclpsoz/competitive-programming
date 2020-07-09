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

int a, b, c;

bool check (int x, int y, int z) {
	if (x != y and y != z and x != z and x*x+y*y+z*z == c and x+y+z == a and x*y*z == b) return true;
	return false;
}

int main ()
{
	int t;
	bool ans;
	scanf ("%d", &t);
	while (t--) {
		ans = false;
		scanf ("%d %d %d", &a, &b, &c);
		for (int x = -100; !ans and x <= 100; x++) {
			if (x*x > c) continue;
			for (int y = -100; !ans and y <= 100; y++) {
				if (x*x+y*y > c) continue;
				for (int z = -100; !ans and z <= 100; z++) {
					if(x*x+y*y+z*z > c) continue;
					if (check (x, y, z)) {
						printf ("%d %d %d\n", x, y, z);
						ans = true;
					}
				}
			}
		}
		if (!ans) printf ("No solution.\n");
	}

	return 0;
}
