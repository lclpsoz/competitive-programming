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

using pp = pair<vector<int>, vector<int>>;

const int N = 3e3+10;

int n, v;
pp days[N];
int fruits[N];

int main () {
	scanf ("%d %d", &n, &v);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		days[x].x.push_back (i);
		days[x+1].y.push_back (i);
		fruits[i] = y;
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int ax = v;
		pp &today = days[i];
		while (ax and (!today.x.empty() or !today.y.empty())) {
			while (ax and !today.y.empty()) {
				int fr = today.y.back();
				int mn = min (fruits[fr], ax);
				fruits[fr] -= mn;
				ax -= mn;
				if (!fruits[fr]) today.y.pop_back();
			}
			while (ax and !today.x.empty()) {
				int fr = today.x.back();
				int mn = min (fruits[fr], ax);
				fruits[fr] -= mn;
				ax -= mn;
				if (!fruits[fr]) today.x.pop_back();
			}
		}
		ans += v-ax;
	}
	printf ("%d\n", ans);

	return 0;
}
