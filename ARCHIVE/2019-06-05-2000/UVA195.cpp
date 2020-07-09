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

string s;

struct classComp {
	bool operator() (const string &l, const string  &r) const {
		for (int i = 0; i < len (l); i++)
			if (tolower (l[i]) < tolower (r[i])) return true;
			else if (tolower (l[i]) > tolower (r[i])) return false;
			else if (tolower (l[i]) == tolower (r[i])) {
				if (l[i] < r[i]) return true;
				else if (l[i] > r[i]) return false;
			}
			
		return false; // Equal
	}
};

set<string, classComp> st;

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	int t;
	cin >> t;
	while (t--) {
		st.clear ();
		cin >> s;
		sort (s.begin(), s.end());
		do {
// 			cout << s << '\n';
			st.insert (s);
		} while (next_permutation (s.begin(), s.end()));
		for (auto &str : st)
			cout << str << '\n';
	}

	return 0;
}
