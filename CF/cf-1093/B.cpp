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

int t;
int qnt[100];

int main () {
	cin >> t;
	while (t--) {
		memset (qnt, 0, sizeof qnt);
		string str;
		cin >> str;
		if (len (str) == 1)
			printf ("-1\n");
		else {
			int pos = -1;
			for (int i = 1; i < len (str); i++)
				if (str[i] != str[0])
					pos = i;
			if (pos == -1)
				cout << -1 << '\n';
			else {
				swap (str[len(str)-1], str[pos]);
				cout << str << '\n';
			}
		}
	}

	return 0;
}
