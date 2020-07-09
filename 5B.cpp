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

vector<string> vec;

int main () {
	// ios::sync_with_stdio (false);
	string str;
	int maxi = 0;
	while (getline (cin, str)) {
		vec.push_back (str);
		// cout << str << '\n';
		maxi = max (len (str), maxi);
	}
	for (int i = 0; i < maxi+2; i++)
		putchar ('*');
	putchar ('\n');
	bool left = true;
	for (string s : vec) {
		putchar ('*');
		int dif = maxi - len (s);
		if (left) {
			if (dif%2)
				left = false;
			for (int i = 0; i < dif/2; i++)
				putchar (' ');
			cout << s;
			for (int i = 0; i < dif/2 + dif%2; i++)
				putchar (' ');
		} else {
			if (dif%2)
				left = true;
			for (int i = 0; i < dif/2 + dif%2; i++)
				putchar (' ');
			cout << s;
			for (int i = 0; i < dif/2; i++)
				putchar (' ');
		}
		putchar ('*');
		putchar ('\n');
	}
	for (int i = 0; i < maxi+2; i++)
		putchar ('*');
	putchar ('\n');

	return 0;
}
