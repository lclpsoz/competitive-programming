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

int n;
string str;

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	
	cin >> n;
	cin >> str;
	for (int i = 0; i < len (str); i++)
		if (str[i] == '?')
			str[i] = '-';
	for (int i = 1; i < n; i++) {
		string ax;
		cin >> ax;
		for (int i = 0; i < len (str); i++)
			if (ax[i] != '?' and str[i] != ax[i]) {
				if (str[i] == '-')
					str[i] = ax[i];
				else
					str[i] = '?';
			}
	}
	
	for (int i = 0; i < len (str); i++)
		putchar (str[i] == '-' ? 'a' : str[i]);
	putchar ('\n');

	return 0;
}
