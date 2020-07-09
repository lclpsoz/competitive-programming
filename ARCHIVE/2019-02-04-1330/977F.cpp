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

const int N = 2e5+10;

int n, a[N];
map<int, int> mp;

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		a[i] = x;
		mp[x] = max (mp[x-1] + 1, mp[x]);
	}
	
	int ans = 0;
	int val = -1;
	for (auto p : mp)
		if (p.y > ans) {
			ans = p.y;
			val = p.x;
		}
		
	vector<int> vec;
	for (int i = n; i >= 1; i--)
		if (a[i] == val) {
			--val;
			vec.push_back (i);
		}
	
	reverse (vec.begin(), vec.end());
	printf ("%d\n", ans);
	for (int i = 0; i < ans; i++)
		printf ("%d%c", vec[i], " \n"[i == ans-1]);
	
	return 0;
}
