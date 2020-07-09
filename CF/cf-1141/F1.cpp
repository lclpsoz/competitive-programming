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

int n;
vector<int> vals;
int pref[55];
int dp[55][55];
int valNow;

int solve (int l, int r) {
	if (l == r) return (pref[r] - pref[l-1]) == valNow;
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	ret = (pref[r] - pref[l-1]) == valNow;
	for (int mid = l; mid < r; mid++)
		ret = max (ret, solve (l, mid) + solve (mid+1, r));
	
	return ret;
}

void recu (int l, int r) {
	if (l == r)
		if ((pref[r] - pref[l-1]) == valNow) {
			printf ("%d %d\n", l, r);
			return;
		}
		
	int &ret = dp[l][r];
	if (ret == ((pref[r] - pref[l-1]) == valNow)) {
		if (ret == 1)
			printf ("%d %d\n", l, r);
		return;
	}
	for (int mid = l; mid < r; mid++)
		if (solve (l, mid) + solve (mid+1, r) == ret) {
			recu (l, mid);
			recu (mid+1, r);
			return;
		}
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &pref[i]);
		pref[i] += pref[i-1];
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			vals.push_back (pref[j]-pref[i-1]);
	sort (vals.begin(), vals.end());
	vals.resize( unique (vals.begin(), vals.end()) - vals.begin());
	
	int ans = 0;
	int bstVal = - 1e9;
	for (int v : vals) {
		valNow = v;
		memset (dp, -1, sizeof dp);
		if (solve (1, n) > ans) {
			ans = solve (1, n);
			bstVal = v;
		}
	}
	
	valNow = bstVal;
	memset (dp, -1, sizeof dp);
	printf ("%d\n", ans);
	if (ans > 0) {
		solve (1, n);
		recu (1, n);
	}

	return 0;
}
