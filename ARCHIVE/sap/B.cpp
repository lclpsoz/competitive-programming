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

map<string, string> mp;

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	int n, m;
	cin >> n >> m;
	string st = "A";
	while (m--) {
		string a, b;
		cin >> a >> b;
		// cout << "a = " << a << " b = " << b << '\n';
		mp[a] = b;
	}
	while (n--) {
		vector<string> vec;
		char lst = st[0];
		vec.push_back ("");
		for (int i = 0; i < len (st); i++) {
			// cout << st[i] << '\n';
			string now(1,st[i]);
			if (st[i] != lst) {
				vec.push_back (now);
				// cout << " HERE: " << " " + st[i] << '\n';
				// cout << "back: " << vec[len(vec)-1] << '\n';
				lst = st[i];
			} else
				vec[len(vec)-1] = vec[len(vec)-1] + now;
		}
		// cout << "lenVec = " << len (vec) << '\n';
		for (int i = 0; i < len (vec); i++) {
			// cout << "  " << i << ": " << vec[i] << '\n';
			vec[i] = mp[vec[i]];
		}
		st = "";
		for (string s : vec)
			st += s;
		// cout << st << '\n';
	}
	// cout << st << '\n';
	int qA, qB;
	qA = qB = 0;
	for (char c : st)
		qA += c == 'A', qB += c == 'B';
	cout << qA << ' ' << qB << '\n';

	return 0;
}
