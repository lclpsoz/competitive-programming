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

const int N = 2e5 + 10;

int n;
map<int, int> dp;
map<int, int> bef, lst;
set<int> st;
int a[N]; ;

int main () {
	scanf ("%d", &n);
	int mx = -1, val = -1;
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		a[i] = x;
		if (dp[x-1] and dp[x-1] + 1 > dp[x]) {
			bef[x] = lst[x-1];
			dp[x] = dp[x-1]+1;
		}
		if (dp[x] == 0) {
			bef[x] = -1;
			dp[x] = 1;
		}
		lst[x] = i;
		if (dp[x] > mx) {
			mx = dp[x];
			val = x;
		}
	}
	int le = mx;
	vector<int> ans;

	ans.push_back (lst[val]+1);
	while (len (ans) < le) {
		ans.push_back (bef[val]+1);
		--val;
	}
	reverse (ans.begin(), ans.end());
	printf ("%d\n", le);
	for (int v : ans)
		printf ("%d ", v);
	putchar ('\n');

	return 0;
}
