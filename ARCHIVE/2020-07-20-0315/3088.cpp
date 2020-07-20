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
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

char str[101010];

int main () {
	while(scanf("%[^\n]", str) != EOF) {
		int n = strlen(str);
		str[n] = '\n'; getchar();
		str[n+1] = '\0';
		for(int i = 0; i < n; i++)
			if(!(str[i] == ' ' and (str[i+1] == '.' or str[i+1] == ',')))
				putchar(str[i]);
		putchar(str[n]);
	}

	return 0;
}
