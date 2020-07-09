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

ll arr[5][5];
char opr[5];

ll solve (int p) {
	/*for (int i = 0; i < p+1; i++)
		printf ("%lld ", arr[p+1][i]);
	putchar ('\n');*/
	if (p == 0)
		return arr[1][0];
	ll r = 1e18;
	for (int i = 0; i <= p; i++)
		for (int j = i+1; j <= p; j++) {
			if (opr[3-p] == '+')
				arr[p][0] = arr[p+1][i] + arr[p+1][j];
			else
				arr[p][0] = arr[p+1][i] * arr[p+1][j];
			int pos = 1;
			for (int k = 0; k <= p; k++)
				if (k != i && k != j)
					arr[p][pos++] = arr[p+1][k];

			r = min (r, solve (p-1));
		}
		
	return r;
}

int main () {
	for (int i = 0; i < 4; i++)
		scanf ("%lld", &arr[4][i]);
	for (int i = 0; i < 3; i++)
		scanf (" %c", &opr[i]);
	printf ("%lld\n", solve (3));
	
	return 0;
}
