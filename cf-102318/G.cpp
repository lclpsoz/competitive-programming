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

int needed[55];
double prob[55];
float dp[10010][51][51];
bool vis[10010][51][51];

float solve(int a, int g, int c) {
	// if(g < 0)
	// 	printf("    G < 0!\n");
	if(g < 0) return 1;
	if(needed[g] == c) {
		return solve(a, g-1, 0);
	}
	// if(a == 0)
	// 	printf("    A == 0!\n");
	if(a == 0) return 0;
	// printf("a = %d, g = %d, c = %d, needed[g] = %d, prob[g] = %lf\n", a, g, c, needed[g], prob[g]);
	if(vis[a][g][c]) return dp[a][g][c];
	vis[a][g][c] = true;
	float &ret = dp[a][g][c];
	return ret = solve(a-1, g, c+1)*prob[g] + 
					solve(a-1, g, c)*(1-prob[g]);
}

int main () {
	// double x = 0.0115l + EPS;
	// printf("%.3lf == 0.012\n", x);
	int t;
	scanf("%d", &t);
	while(t--) {
		int g;
		scanf("%d", &g);
		for(int i = 0; i < g; i++) {
			int c;
			double p;
			scanf("%d %lf", &c, &p);
			needed[i] = c;
			prob[i] = p;
		}
		int a;
		scanf("%d", &a);
		for(int i = 0; i <= a; i++)
			memset(vis[i], 0, sizeof vis[i]);
		printf("%.3f\n", solve(a, g-1, 0));
		// for(int i = 0; i <= a; i++) {
		// 	printf("%d: ", a);
		// 	for(int j = 0; j < g; j++) {
		// 		printf("%lf ", dp[i][j][0]);
		// 	}
		// 	putchar('\n');
		// }
	}

	return 0;
}
