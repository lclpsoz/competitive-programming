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

const int INF = 1e9 + 10;
const int MSK = 1<<20;

int n, m;
int mat[25][25];
int dp[MSK];
int enMsk;

int solve (int msk) {
	int &ret = dp[msk];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i < m; i++) {
		// printf ("msk = %d, i = %d, %d\n",msk ,i,(1<<i)&msk);
		if (((1<<i)&msk) == 0)
			ret = min (ret, solve (msk | (1<<i)));
	}
	// printf ("%d: %d\n", msk, ret);
	if (ret == INF) ret = 0;
	for (int i = 0; i < m; i++)
		if ((1<<i)&msk)
			for (int j = 0; j < m; j++)
				if (((1<<j)&msk) == 0)
					ret += mat[i][j];
	// printf ("%d: %d\n", msk, ret);
	return ret;
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d %d", &n, &m);
	enMsk = (1<<m)-1;
	char bef;
	--n;
	scanf (" %c", &bef);
	while (n--) {
		char c;
		scanf (" %c", &c);
		mat[bef-'a'][c-'a']++;
		mat[c-'a'][bef-'a']++;
		bef = c;
	}

	printf ("%d\n", solve (0));


	return 0;
}