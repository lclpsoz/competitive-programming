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

int getRange (int x1, int y1, int x2, int y2) {
	cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
	cout << flush;
	int ret;
	cin >> ret;
	if (ret == -1) exit (0);
	return ret;
}

int bsCol (int col) {
	int l = 1, r = n;
	while (l < r) {
		int md = (l+r)/2;
		if (getRange (l, col, md, col)%2 == 1)
			r = md;
		else
			l = md+1;
	}

	return l;
}

int bsRow (int row) {
	int l = 1, r = n;
	while (l < r) {
		int md = (l+r)/2;
		if (getRange (row, l, row, md)%2 == 1)
			r = md;
		else
			l = md+1;
	}

	return l;
}

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cin >> n;

	vector<int> cols;
	for (int i = 1; i < n; i++) { // 999
		int now = getRange (1, i, n, i);
		if (now%2 == 1)
			cols.push_back (i);
	}
	if (len (cols) > 0) {
		if (len (cols) == 1)
		cols.push_back (n);
		int c1 = bsCol (cols[0]);
		int c2 = bsCol (cols[1]);
		cout << "! " << c1 << ' ' << cols[0] << ' ' << c2 << ' ' << cols[1] << '\n';
		cout << flush;
	} else {
		vector<int> rows;
		for (int i = 1; i < n; i++) { // 999 | 1998
			int now = getRange (i, 1, i, n);
			if (now%2 == 1)
				rows.push_back (i);
		}
		if (len (rows) == 1) rows.push_back (n);
		assert (len (rows) == 2);
		int c1 = bsRow (rows[0]);
		int c2 = bsRow (rows[1]);
		cout << "! " << rows[0] << ' ' << c1 << ' ' << rows[1] << ' ' << c2 << '\n';
		cout << flush;
	}

	return 0;
}
