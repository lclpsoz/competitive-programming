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

const int N = 5e5+100;

int n, k;
int dp[N][30];
char arr[N];

int solve (int p, int bef) {
	if (p == n)
		return 0;
	int &r = dp[p][bef];
	if (r != -1) return r;
	r = 1e8;
	for (int i = 0; i < k; i++)
		if (i != bef) {
			if (arr[p] == i)
				r = min (r , solve (p+1, i));
			else
				r = min (r, solve (p+1, i) + 1);
		}
		
	return r;
}

int rec (int p, int bef) {
	if (p == n)
		return 0;
	int &r = dp[p][bef];
	for (int i = 0; i < k; i++)
		if (i != bef) {
			if (arr[p] == i) {
				if (rec (p+1, i) == r) {
					arr[p] = i;
					return r;
				}
			} else {
				if (rec (p+1, i)+1 == r) {
					arr[p] = i;
					return r;
				}
			}
		}
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d %d", &n, &k);
	scanf ("%s", arr);
	for (int i = 0; i < n; i++)
		arr[i] -= 'A';
	
	int choosen = 0, ans = 1e9;
	for (int i = 0; i < k; i++)
		if (solve (0, i) < ans) {
			ans = solve (0, i);
			choosen = i;
		}
 	for (int i = 0; i < n; i++) {
 		for (int j = 0; j < k; j++)
 			printf ("%d ", dp[i][j]);
 		putchar ('\n');
 	}
	rec (0, choosen);
	printf ("%d\n", ans);
	for (int i = 0; i < n; i++)
		putchar (arr[i]+'A');
	putchar ('\n');
	
	return 0;
}
