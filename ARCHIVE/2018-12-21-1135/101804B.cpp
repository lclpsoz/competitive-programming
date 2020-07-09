#include "vector"
#include "stdio.h"
#include "string.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

////////////////////////// Solution starts below. //////////////////////////////

const int INF = 1e9;
const int M = 1e3+10, W = 2100;

int wkit, m, n;
int wei[M];
char names[M][15];
int dp[M][W];

int solve (int p, int v) {
	if (v <= 0)
		return 0;
	if (p > m)
		return INF;
	
	int &r = dp[p][v];
	if (r != -1)
		return r;
	r = INF;
	r = min (solve (p+1, v), solve (p+1, v-wei[p]) + wei[p]);
	
	return r;
}

void rec (int p, int w, vector<int> &ans) {
	if (w <= 0 or p > m)
		return;
	if ((solve (p+1, w-wei[p]) + wei[p]) < solve (p+1, w)) {
		ans.push_back (p);
		rec (p+1, w-wei[p], ans);
	} else
		rec (p+1, w, ans);
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d %d", &wkit, &m);
	for (int i = 1; i <= m; i++)
		scanf ("%s %d", names[i], &wei[i]);
	
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int w;
		scanf ("%d", &w);
		w = ((w+1)/2) - wkit;
		if (solve (1, w) == INF)
			printf ("-1\n");
		else {
			vector<int> ans;
			rec(1, w, ans);
			printf ("%d", len (ans));
			for (int v : ans)
				printf (" %s", names[v]);
			putchar ('\n');
		}
	}
	
	return 0;
}
