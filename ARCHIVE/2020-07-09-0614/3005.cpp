#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int main () {
	int n;
	scanf ("%d", &n);
	while (n--) {
		vector<int> v1, v2;
		for (int i = 0; i < 3; i++) {
			int x;
			scanf ("%d", &x);
			v1.push_back (x);
		}
		for (int i = 0; i < 3; i++) {
			int x;
			scanf ("%d", &x);
			v2.push_back (x);
		}
		sort (v1.begin(), v1.end());
		sort (v2.begin(), v2.end());
		bool t1, t2;
		t1 = t2 = false;
		t1 = v1[0] < v2[1] and v1[1] < v2[2];
		t2 = v2[0] < v1[1] and v2[1] < v1[2];
		if (!t1 and !t2)
			printf ("0\n");
		else if (t1 and !t2)
			printf ("1\n");
		else if (!t1 and t2)
			printf ("2\n");
		else
			printf ("3\n");
	}

	return 0;
}
