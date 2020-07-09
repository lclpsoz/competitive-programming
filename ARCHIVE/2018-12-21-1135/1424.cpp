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

int n, m;
unordered_map<int, vector<int>> mp;

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	while (cin >> n >> m) {
		mp.clear();
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			mp[x].push_back (i);
		}
		
		while (m--) {
			int k, v;
			cin >> k >> v;
			if (len (mp[v]) < k)
				cout << 0 << '\n';
			else
				cout << mp[v][k-1] << '\n';
		}
	}

	return 0;
}
