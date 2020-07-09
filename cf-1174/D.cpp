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

const int N = (1<<20) + 10;

int a[N];
int vals[20];

void fi (int aa, int bb, int vv) {
	vector<pair<pii, int>> pi;
	pi.push_back ({{aa, bb}, vv});
	while (!pi.empty()) {
		int l = pi.back().x.x, r = pi.back().x.y, v = pi.back().y;
		pi.pop_back ();
		int md = l + (r-l)/2;
		a[md] = v;
		if (l < r)
			pi.push_back ({{l, md-1}, v+1}), pi.push_back ({{md+1, r}, v+1});
	}
}

int main () {
	// fi(0, 524286, 0);
	// for (int i = 0; i < 15; i++) printf ("%d ", a[i]);
	// putchar ('\n');

	a[0] = 18;
	a[1] = 17;
	a[2] = 18;
	int v = 16;
	for (int i = 4; i <= 262144; i*=2) {
		int p = i-1;
		a[p] = v--;
		for (int j = 0; j < i; j++)
			a[p+j] = a[p-j];
	}

	for (int i = 18; i >= 0; i--)
		vals[i] = 1<<(18-i);
	// for (int i = 0; i < 15; i++) printf ("%d ", vals[a[i]]);
	// putchar ('\n');

	// for (int i = 0; i < 32; i++) {
	// 	printf("%d:\t%d\t", i, vals[a[i]]/2);
	// 	bitset<6> x(i);
	// 	bitset<6> v(vals[a[i]]/2);
	// 	cout << x << ' ' << v;
	// 	putchar ('\n');
	// }

	int n, x;
	scanf ("%d %d", &n, &x);
	if (x >= (1<<n)) {
		printf ("%d\n", (1<<n)-1);
		for (int i = 0; i < (1<<n)-1; i++)
			printf ("%d ", vals[a[i]]);
		putchar ('\n');
	} else {
		int po = 0;
		int xx = x;
		while (xx > 1) {
			po++;
			xx >>= 1;
		}
		int ax = 1<<po;
		int pos = -1;
		for (int i = 18; i >= 18-(n-1); i--)
			if (vals[i] == ax)
				pos = i;
		if (pos != -1) {
			for (int i = pos; i >= 18-(n-1); i--)
				vals[i] *= 2;
		}
		printf ("%d\n", (1<<(n-1))-1);
		for (int i = 0; i < (1<<(n-1))-1; i++)
			printf ("%d ", vals[a[i]]);
		putchar ('\n');
	}

	return 0;
}
