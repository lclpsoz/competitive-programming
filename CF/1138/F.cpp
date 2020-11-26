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

vector<string> mov (vector<int> v) {
	cout << "next";
	for (int x : v)
		cout << ' ' << x;
	cout << '\n';
	cout << flush;

	vector<string >ret;
	string ans;
	cin >> ans;
	if (len (ans) > 1) exit(0);
	int n = ans[0]-'0';
	while (n--) {
		string s;
		cin >> s;
		ret.push_back (s);
	}

	return ret;
}

int main () {
	mov ({0, 1});
	mov ({0});
	vector<string> vec;
	do {
		mov ({0, 1});
		vec = mov ({0});
	} while (len (vec) > 2);
	do {
		vec = mov ({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
	} while (len (vec) > 1);
	cout << "done\n";
	cout << flush;

	return 0;
}
