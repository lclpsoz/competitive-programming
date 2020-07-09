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

const int N = 5005;

int n;
bool vis[2*N][N];
bool dp[2*N][N];
string sClown, sAcr;

bool isClown (int p) {
	return sClown[p-1] == '1';
}

bool isAcr (int p) {
	return sAcr[p-1] == '1';
}

bool solve (int diff, int p) {
	for (int i = 0; i < p; i++)
		printf ("  ");
	printf ("diff = %d, p = %d\n", diff, p);
	if (p > n) return diff == N;
	if (vis[diff][p]) return dp[diff][p];
	vis[diff][p] = true;
	return dp[diff][p] = 
		solve (diff + isClown (p), p+1) or
		solve (diff - isAcr (p), p+1);
}

int rec (int diff, int p) {
	for (int i = 0; i < p; i++)
		printf ("  ");
	printf ("diff = %d, p = %d\n", diff, p);
	if (p > n) return diff == N;
	if (rec (diff + isClown (p), p+1))
		printf ("%d ", p);
	else
		rec (diff - isAcr (p), p+1);
	return true;
}

int main () {
	cin >> n >> sClown >> sAcr;
	
	if (!solve (N, 1))
		printf ("-1");
	else
		rec (N, 1);
	putchar ('\n');
	
	return 0;
}
