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
	if (len (s2) > 1 and s2[0] == '0') {
		printf ("WRONG_ANSWER\n");
		exit (0);
	}
	
	string a, b;
	a = s1, b = s2;
	sort (a.begin(), a.end());
	sort (b.begin(), b.end());
	if (len (a) != len (b)) {
		printf ("WRONG_ANSWER\n");
		exit (0);
	}
	for (int i = 0; i < len (a); i++) {
		if (a[i] != b[i]) {
			printf ("WRONG_ANSWER\n");
			exit (0);
		}
	}
	
	for (int i = 1; i < len (s2); i++)
		if (s2[i] != '0' and s2[i] < s2[0]) {
			printf ("WRONG_ANSWER\n");
			exit (0);
		}
	for (int j = 1; j < len (s2); j++)
		for (int i = j+1; i < len (s2); i++)
			if (s2[i] < s2[j]) {
				printf ("WRONG_ANSWER\n");
				exit (0);
			}
		
	printf ("OK\n");

	return 0;
}
