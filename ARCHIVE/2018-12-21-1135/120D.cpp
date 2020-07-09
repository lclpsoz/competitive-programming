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

using pp = pair<int, pii>;
const int N = 55;


int solve (int *vec, pp p, int n) {
	int r = 0;
	int l1 = 0;
	int sum1 = 0;
	while (l1 < n-2) {
		sum1 += vec[l1];
		if (sum1 == p.x) {
			int l2 = l1+1;
			int sum2 = 0;
			while (l2 < n-1) {
				sum2 += vec[l2];
				if (sum2 == p.y.x) {
					int sum3 = 0;
					for (int i = l2+1; i < n; i++)
						sum3 += vec[i];
					r += sum3 == p.y.y;
				}
				
				++l2;
			}
		}
		
		++l1;
	}
	
	return r;
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	int n, m;
	int rows[N], cols[N], a[5];
	set<pp> st;
	memset (rows, 0, sizeof rows);
	memset (cols, 0, sizeof cols);
	
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			scanf ("%d", &x);
			rows[i] += x;
			cols[j] += x;
		}
	}
	

	for (int i = 0; i < 3; i++)
		scanf ("%d", &a[i]);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++) { 
				if (i == j or i == k or j == k) continue;
				st.insert ({a[i], {a[j], a[k]}});
			}

	int ans = 0;
	for (auto p : st) {
		ans += solve (rows, p, n);
		ans += solve (cols, p, m);/*
		if (solve (cols, p, m)) {
			cout << "COLs\n";
			printf ("(%d, (%d, %d))\n", p.x, p.y.x, p.y.y);
		}
		if (solve (rows, p, n)) {
			cout << "ROWs\n";
			printf ("(%d, (%d, %d))\n", p.x, p.y.x, p.y.y);
		}*/
	}
	
	printf ("%d\n", ans);
	

	return 0;
}
