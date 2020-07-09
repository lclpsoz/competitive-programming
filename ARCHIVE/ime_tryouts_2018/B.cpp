#include <bits/stdc++.h>
using namespace std;

// ------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

// ------------

string s;

int main () {
	cin >> s;
	char bef = '-';
	int qnt = 0;
	for (int i = 0; i < len (s); i++) {
		if (s[i] == bef)
			++qnt;
		else {
			qnt = 1;
			bef = s[i];
		}
		if (qnt == 3) {
			qnt = 0;
			bef = '-';
			if (s[i] == 'C')
				putchar ('P');
			else
				putchar ('T');
		} else {
			if (s[i] == 'C')
				putchar ('B');
			else
				putchar ('D');
		}
	}
	putchar ('\n');

	return 0;
}