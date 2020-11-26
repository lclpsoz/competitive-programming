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
string s;

int main () {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	while(n--) {
		cin >> s;
		sort(s.begin(), s.end());
		int d = 0, l = 0, u = 0, r = 0;
		for(int i = 0; i < len(s); i++)
			if(s[i] == 'D') d++;
			else if(s[i] == 'L') l++;
			else if(s[i] == 'R') r++;
			else u++;
		l = min(l, r);
		d = min(d, u);
		if(l == 0) {
			d = min(d, 1);
		}
		if(d == 0) {
			l = min (l, 1);
		}
		cout << 2*l+2*d << '\n';
		for(int i = 0; i < l; i++)
			cout << 'R';
		for(int i = 0; i < d; i++)
			cout << 'U';
		for(int i = 0; i < l; i++)
			cout << 'L';
		for(int i = 0; i < d; i++)
			cout << 'D';
		cout << '\n';
	}

	return 0;
}
