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

const int INF = 2e9;
const int V = 1e5+100;

int n, wMax;
int dp[V];

int main () {
	for (int i = 0; i < V; i++)
		dp[i] = INF;
	dp[0] = 0;
	scanf ("%d %d", &n, &wMax);
	while (n--) {
		int wi, vi;
		scanf ("%d %d", &wi, &vi);
		for (int i = V-1; i >= vi; i--)
			if (dp[i-vi] != INF and (dp[i-vi] + wi) <= wMax)
				dp[i] = min (dp[i], dp[i-vi] + wi);
	}
	
	for (int i = V-1; i >= 0; i--)
		if (dp[i] != INF) {
			printf ("%d\n", i);
			exit (0);
		}
	
	return 0;
}
