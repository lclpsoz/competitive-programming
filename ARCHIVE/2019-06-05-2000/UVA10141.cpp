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

int n, p;
string ans;
int bstR;
ld bstValue;

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	int caso = 1;
	while (cin >> n >> p, n) {
		string ax;
		cin.ignore();
		while (n--) {
			getline (cin, ax);
// 			cout << ax << '\n';
		}
		
		bstValue = 1e1000l;
		bstR = -1;
		while (p--) {
			ld now;
			int r;
			getline (cin, ax);
			cin >> now >> r;
			if (r > bstR) {
				bstR = r;
				bstValue = now;
				ans = ax;
			} else if (r == bstR and cmp (now, bstValue) == -1) {
				bstValue = now;
				ans = ax;
			}
			cin.ignore();
			while (r--)
				getline (cin, ax);
		}
		if (caso > 1)
			cout << '\n';
		cout << "RFP #" << caso++ << '\n';
		cout << ans << '\n';
	}

	return 0;
}
