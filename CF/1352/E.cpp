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
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int a[8080];
int vals[8080];

int main () {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) vals[i] = 0;
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for(int i = 0; i < n-1; i++) {
			int sum = a[i];
			for(int j = i+1; j < n; j++) {
				sum += a[j];
				if(sum <= n) vals[sum] = 1;
				else break;
			}
		}
		if(n == 1) {
			printf("0\n");
			continue;
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
			ans += vals[a[i]];
		printf("%d\n", ans);
	}

	return 0;
}
