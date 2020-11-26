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

const int MOD = 998244353;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5+100;

int n;
char str[N];
int pref, suf;

int main () {
	scanf ("%d %s", &n, str);
	
	pref = suf = 1;
	for (int i = 1; i < n; i++)
		if (str[i] == str[i-1])
			++pref;
		else
			break;
	for (int i = n-2; i > 0; i--)
		if (str[i] == str[i+1])
			++suf;
		else
			break;
		
	if (str[0] == str[n-1])
		printf ("%d\n", mod (pref*1LL*suf + pref + suf + 1));
	else
		printf ("%d\n", pref + suf + 1);
		

	return 0;
}