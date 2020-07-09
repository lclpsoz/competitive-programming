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
	int t;
	cin >> t;
	for (int caso = 1; caso <= t; caso++) {
		string a, b;
		cin >> a;
		b = a;
		for (int i = 0; i < len (a); i++)
			if (a[i] == '4')
				a[i] = '3', b[i] = '1';
			else
				b[i] = '0';
			
		cout << "Case #" << caso << ": ";
		cout << a << ' ';
		bool lef = false;
		for (int i = 0; i < len (a); i++) {
			if (!lef and b[i] != '0')
				lef = true;
			if (lef) putchar (b[i]);
		}
		if (!lef) putchar ('0');
		putchar ('\n');
	}

	return 0;
}
