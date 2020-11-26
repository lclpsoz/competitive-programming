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

int n, x[5];

int main () {
	scanf("%d", &n);
	while(n--) {
		for(int i = 0; i < 3; i++)
			scanf("%d", &x[i]);
		sort(x, x+3);
		// printf("%d %d %d\n", x[0], x[1], x[2]);
		if(x[1] > x[0])
			x[0]++;
		else if(x[1] == x[0] and x[1] < x[2])
			x[0]++, x[1]++;
		if(x[2] > x[1])
			x[2]--;
		else if(x[0] != x[1])
			x[1]--, x[2]--;
		// printf("%d %d %d\n", x[0], x[1], x[2]);
		printf("%d\n", x[2]-x[0] + x[1]-x[0] + x[2]-x[1]);
	}

	return 0;
}
