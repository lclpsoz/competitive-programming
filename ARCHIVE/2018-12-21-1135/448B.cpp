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

string s1, s2;

int main () {
	cin >> s1 >> s2;
	
	bool test = false;
	for (int i = 0, j = 0; i < len (s1); i++) {
		if (s1[i] == s2[j])
			++j;
		if (j == len (s2)) {
			test = true;
			break;
		}
	}
	if (test) {
		printf ("automaton\n");
		return 0;
	}
	
	for (int i = 0; i < len (s2); i++) {
		test = false;
		for (int j = 0; j < len (s1); j++)
			if (s1[j] == s2[i]) {
				test = true;
				s1[j] = '-';
				break;
			}
		if (!test) {
			printf ("need tree\n");
			return 0;
		}
	}
	
	if (len (s1) == len (s2))
		printf ("array\n");
	else
		printf ("both\n");

	return 0;
}