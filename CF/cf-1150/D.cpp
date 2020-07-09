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

const int N = 1e5 + 10;
const int S = 255;
const int INF = 1e9 + 100;

int n, q;
int dp[S][S][S];
char str[N];
int nxt[30][N], lst[30];
vector<char> w[5];

int solve (int i, int j, int k) {
	if (i == 0 and j == 0 and k == 0) return 0;
	int &ret = dp[i][j][k];
	if (ret != -1) return ret;
	ret = INF;
	if (i) {
		int p = solve (i-1, j, k);
		if (p != INF and p < n)
			ret = min (ret, nxt[w[0][i-1]][p] + 1);
	}
	// printf ("%d, %d, %d -> %d\n", i, j, k, ret);
	if (j) {
		int p = solve (i, j-1, k);
		if (p != INF and p < n)
			ret = min (ret, nxt[w[1][j-1]][p] + 1);
	}
	// printf ("%d, %d, %d -> %d\n", i, j, k, ret);
	if (k) {
		int p = solve (i, j, k-1);
		if (p != INF and p < n)
			ret = min (ret, nxt[w[2][k-1]][p] + 1);
	}
	// printf ("%d, %d, %d -> %d\n", i, j, k, ret);

	return ret;
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d %d %s", &n, &q, str);
	for (int i = 0; i < n; i++) str[i] -= 'a';

	for (int i = 0; i <= 'z'-'a'; i++) lst[i] = INF;
	for (int i = n-1; i >= 0; i--) {
		lst[str[i]] = i;
		for (int j = 0; j <= 'z'-'a'; j++)
			nxt[j][i] = lst[j];
	}
	// for (int i = 0; i < n; i++) {
	// 	printf ("%d: ", i);
	// 	for (int j = 0; j <= 'd'-'a'; j++)
	// 		printf ("%2d%c", nxt[j][i], " \n"[j=='d'-'a']);
	// }

	while (q--) {
		char opt;
		int id;
		scanf (" %c %d", &opt, &id);
		id--;
		if (opt == '+') {
			char c;
			scanf (" %c", &c);
			c -= 'a';
			w[id].push_back (c);
		} else {
			if (id == 0)
				for (int i = 0; i < S; i++)
					for (int j = 0; j < S; j++)
						dp[len(w[0])][i][j] = -1;
			else if (id == 1)
				for (int i = 0; i < S; i++)
					for (int j = 0; j < S; j++)
						dp[i][len(w[1])][j] = -1;
			else if (id == 2)
				for (int i = 0; i < S; i++)
					for (int j = 0; j < S; j++)
						dp[i][j][len(w[2])] = -1;
			// memset (dp, -1, sizeof dp);
			w[id].pop_back ();
		}

		if (solve (len (w[0]), len (w[1]), len (w[2])) == INF)
			printf ("NO\n");
		else
			printf ("YES\n");
		// for (int i = 0; i <= len (w[0]); i++)
		// 	for (int j = 0; j <= len (w[1]); j++)
		// 		for (int k = 0; k <= len (w[2]); k++)
		// 			printf ("dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);
	}

	return 0;
}
