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

int qry = 0;

char check (int l, int r) {
	++qry;
	assert (qry <= 60);
	char ret;
	cout << "? " << l << ' ' << r << '\n';
	cout.flush();
	cin >> ret;
	return ret;
}

int solve (int low, int high) {
	if (low == 1) {
		if (check (2, 1) == 'y') // 2%a == 0 and 1%a == 1, a == 2
			return 2;
		return 1; // 1%a == 0 and 2%a == 0, a == 1
	}
	++low;
	while (low < high-2) {
		int md = (low+high)/2;
		md += md&1;
// 		cout << "md: " << md << '\n';
		cout.flush();
		char now = check (md/2, md);
		if (now == 'x')
			high = md;
		else
			low = md;
	}
	
	if (check (0, high) == 'x')
		return high;
	else if (check (0, high-1) == 'x')
		return high-1;
	return high-2;
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	string str;
	// x -> (val (x) >= val (y))
	// y -> (val (x) < val (y))
	while (cin >> str, str != "end") {
		if (str == "mistake") return 0; // WA
		qry = 0;
		int p = 0;
		char resp = '-';
		while (resp != 'x') {
			++p;
			resp = check ((1<<(p-1)), (1<<(p)));
		}
		
		int ans = solve ((1<<(p-1)), (1<<p));
		cout << "! " << ans << '\n';
		cout.flush();
	}

	return 0;
}
