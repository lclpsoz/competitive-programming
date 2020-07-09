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
	cin.tie (0);
	ios::sync_with_stdio (false);
	cin >> str;
	bool test = false;
	for (int i = 0; i < len (str); i++)
		if (str[i] == '0') {
			str[i] = '_';
			test = true;
			break;
		}
	
	if (!test)
		str[0] = '_';
	for (int i = 0; i < len (str); i++)
		if (str[i] != '_')
			putchar (str[i]);
	putchar ('\n');

	return 0;
}
