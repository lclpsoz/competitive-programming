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

const int N = 1e6+10;

int n;
char str[N];
int st;
int qnt;

int main () {
	scanf ("%d", &n);
	scanf ("%s", str);
	bool valid = true;
	for (int i = 0; i < n; i++) {
		if (str[i] == ')') {
			if (!st) {
				valid = false;
				break;
			}
			--st;
			if (st < 2)
				qnt = min (qnt-1, 1);
		} else {
			++st;
			++qnt;
		}
	}
	if (!valid) {
		st = 0;
		reverse (str, str+n);
		for (int i = 0; i < n; i++)
			str[i] = (str[i] == ')' ? '(' : ')');
		valid = true;
		qnt = 0;
		for (int i = 0; i < n; i++) {
			if (str[i] == ')') {
				if (!st) {
					valid = false;
					break;
				}
				--st;
				if (st < 2)
					qnt = min (qnt-1, 1);
			} else {
				++st;
				++qnt;
			}
		}
	}
	
	if (!valid or st == 0 or st > 2 or n&1)
		printf ("0\n");
	else
		printf ("%d\n", qnt-1);

	return 0;
}
