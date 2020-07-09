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

const int N = 3e5 + 10;

vector<pii> segments;
char str[N];

int main () {
	scanf (" %s", str);
	int n = strlen (str);
	for (int i = 1; i < n-1; i++)
		for (int j = 1; i-j >= 0 and i+j < n and j < 20; j++)
			if (str[i] == str[i-j] and str[i] == str[i+j]) {
				segments.push_back ({i-j, i+j});
				break;
			}

	sort (segments.begin(), segments.end(), [&] (pii a, pii b) {
		if (a.y != b.y) return a.y < b.y;
		return a.x > b.x;
	});
	int st = 0;
	ll ans = 0;
	for (auto p : segments) {
		// printf ("%d %d, st = %2d, ans = %4d ", p.x, p.y, st, ans);
		if (p.x >= st) {
			ans += (p.x-st+1)*1LL*(n-1-p.y+1);
			st = p.x + 1;
			// printf ("COOL");
		}
		// putchar ('\n');
	}
	printf ("%lld\n", ans);

	return 0;
}
