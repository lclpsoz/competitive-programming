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
string str;
string base = "RGB";
vector<string> perm;

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	sort (base.begin(), base.end());
	do {
		perm.push_back (base);
	} while (next_permutation (base.begin(), base.end()));
	cin >> n >> str;
	int ans = 1e9;
	string bst;
	for (string p : perm) {
		int now = 0;
		int j = 0;
		for (int i = 0; i < len (str); i++, j++) {
			if (j == 3) j = 0;
			if (str[i] != p[j]) ++now;
		}
		if (now < ans) {
			ans = now;
			bst = p;
		}
	}
	
	cout << ans << '\n';
	for (int i = 0; i < len (str); i++)
		cout << bst[i%3];
	cout << '\n';

	return 0;
}
