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

int k;
string str;
int qStar, qCane;

int main () {
	cin >> str >> k;
	for (int i = 0; i < len (str); i++)
		if (str[i] == '*')
			++qStar;
		else if (str[i] == '?')
			++qCane;
	
	int qLetters = len (str)-qCane-qStar; // Amount of letters
	if (k < (qLetters-qCane-qStar) or
		(k > qLetters and qStar == 0))
		printf ("Impossible");
	else if (k < qLetters) {
		for (int i = 0; i < len (str); i++)
			if (str[i] != '*' and str[i] != '?') {
				if (i < len (str)-1 and (str[i+1] == '*' or str[i+1] == '?') and k < qLetters)
					qLetters--;
				else
					putchar (str[i]);
					
			}
	} else if (k > qLetters) {
		k -= qLetters;
		for (int i = 0; i < len (str); i++)
			if (str[i] != '*' and str[i] != '?') {
				putchar (str[i]);
				if (i < len(str)-1)
					while (k and str[i+1] == '*') {
						putchar (str[i]);
						--k;
					}
			}
	} else if (k == qLetters) {
		for (int i = 0; i < len (str); i++)
			if (str[i] != '*' and str[i] != '?')
				putchar (str[i]);
	}
	putchar ('\n');

	return 0;
}
