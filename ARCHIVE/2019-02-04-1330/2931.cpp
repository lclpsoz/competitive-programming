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

map<string, set<string>> mp;

int n, k;

int main () {
//     cin.tie (0);
//     ios::sync_with_stdio (false);
	while (cin >> n >> k) {
		mp.clear();
		cin.ignore();
		while (n--) {
			string base;
			getline (cin, base);
// 			cout << "base: " << base << '\n';
			set<string> &now = mp[base];
			int s;
			cin >> s; cin.ignore();
// 			cout << s << '\n';
// 			cin.ignore();
			while (s--) {
				string str;
				getline (cin, str);
				now.insert (str);
			}
		}

		for (int i = 0; i < k; i++) {
			string crianca;
			getline (cin, crianca);
	// 			cout << crianca << '\n';
			int p = 0;
			while (crianca[p] != ';') ++p;
			string base = crianca.substr (0, p);
			++p;
			string str = crianca.substr (p, len (crianca)-p);
	// 			cout << base << ' ' << str << '\n';
			if (mp[base].count (str))
				cout << "Y\n";
			else
				cout << "N\n";
		}
	}

	return 0;
}
