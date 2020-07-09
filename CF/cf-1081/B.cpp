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

const int N = 1e5+10;

int ans[N];
vector<pii> vec;

int main () {
	int n;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		vec.push_back ({x, i});
	}
	sort (vec.begin(), vec.end());
	
	int p = 0, pst = 0, id = 1;
	bool state = true;
	while (state and p < n) {
		int qnt = n - vec[p].x;
		for (int i = p; i < p+qnt; i++) {
			if (vec[i].x == vec[p].x) {
				ans[vec[i].y] = id;
			} else {
				state = false;
				break;
			}
		}
		p += qnt;
		++id;
	}
	if (state) {
		printf ("Possible\n");
		for (int i = 1; i <= n; i++)
			printf ("%d%c", ans[i], " \n"[i==n]);
	} else
		printf ("Impossible\n");

	return 0;
}
