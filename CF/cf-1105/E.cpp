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
int ans;
map<string, int> mp;

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	cin >> n >> m;
	int maxi = -1;
	while (n--) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			if (maxi != -1) {
				ans += maxi;
				maxi = -1;
				mp.clear();
			}
		} else {
			string str;
			cin >> str;
			mp[str]++;
			maxi = max (maxi, mp[str]);
		}
	}
	if (!mp.empty())
		ans += maxi;
	cout << ans << '\n';

	return 0;
}
