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

string str;

int main () {
	cin >> str;
	int l, r, n = len (str);
	l = 0, r = n-1;
	while (l < n and str[l] != '[') ++l;
	while (r >= 0 and str[r] != ']') --r;
	if (l >= r)
		printf ("-1\n");
	else {
		while (l < n and str[l] != ':') ++l;
		while (r >= 0 and str[r] != ':') --r;
		if (l >= r)
			printf ("-1\n");
		else {
			int q = 4;
			for (int i = l+1; i < r; i++)
				q += str[i] == '|';
			printf ("%d\n", q);
		}
	}

	return 0;
}
