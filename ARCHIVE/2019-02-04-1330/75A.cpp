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

string remZero (string str) {
	string ret;
	for (int i = 0; i < len (str); i++)
		if (str[i] != '0')
			ret += str[i];
		
	return ret;
}

int main () {
	int a, b;
	scanf ("%d %d", &a, &b);
	string x = remZero (to_string (a));
	string y = remZero (to_string (b));
	string z = remZero (to_string (a+b));
	int z2 = stoi (x) + stoi (y);
	printf ("%s\n", stoi (z) == z2 ? "YES" : "NO");

	return 0;
}
