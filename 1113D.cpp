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

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	string s;
	cin >> s;
	bool rep = false;
	for (int i = 1; !rep and i < len (s); i++)
		if (s[i] != s[i-1]) rep = true;

	if (!rep)
		cout << "Impossible\n";
	else {
		if (len (s)%2 == 1) {
			bool ok = false;
			for (int i = 1; !ok and i < len(s)/2; i++)
				if (s[i] != s[i-1]) ok = true;
			if (!ok)
				cout << "Impossible\n";
			else
				cout << 2 << '\n';
		} else {
			set<string> st;
			for (int i = 1; i < len(s); i++)
				st.insert (s.substr(i) + s.substr (0, i));
			st.erase (s);
			for (string x : st) {
				bool ok = true;
				for (int i = 0; ok and i < len (x)/2; i++)
					if (x[i] != x[len(x)-1-i]) ok = false;
				if (ok) {
					cout << 1 << '\n';
					exit (0);
				}
			}
			cout << 2 << '\n';
		}
	}

	return 0;
}
