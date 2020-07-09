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
string tree;
map<string, int> mp;

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	cout << fixed;
	cout << setprecision (4);
	cin >> n;
	getline (cin, tree); // First blank line
	getline (cin, tree); // Second blank line
	while (n--) {
		mp.clear();
		int qnt = 0;
		while (getline (cin, tree) and tree != "") {
			mp[tree]++;
			++qnt;
		}
		for (auto p : mp) {
			cout << p.x << ' ' << 100*(double)p.y/qnt << '\n';
		}
		if (n > 0)
			cout << '\n';
	}

	return 0;
}
