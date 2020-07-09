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

const int INF = 1e9;

int n;
int dp[110][55], q[110], w[110];
int qNotUsed;
int totalW;

int solve (int p, int fr) {
	if (fr < 0) return -INF;
	if (p == n) return 0;
	int &ret = dp[p][fr];
	if (ret != -1) return ret;
	return ret = max (solve (p+1, fr), solve (p+1, fr-w[p]) + q[p]);
}

void recu (int p, int fr) {
	if (p == n) return;
	if (fr < 0) return;
	if (solve (p+1, fr) > solve (p+1, fr-w[p]) + q[p]) {
		qNotUsed++;
		recu (p+1, fr);
	} else {
		totalW += w[p];
		recu (p+1, fr-w[p]);
	}
}

int main () {
	int t;
	scanf ("%d", &t);
	while (t--) {
		totalW = 0;
		qNotUsed = 0;
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d %d", &q[i], &w[i]);
		memset (dp, -1, sizeof dp);
		int qTotal = solve (0, 50);
		recu (0, 50);
		printf ("%d brinquedos\n", qTotal);
		printf ("Peso: %d kg\n", totalW);
		printf ("sobra(m) %d pacote(s)\n", qNotUsed);
		putchar ('\n');
	}

	return 0;
}
