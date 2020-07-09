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

const int N = 2e5 + 10, INF = 1e9;

int n, k;
int arr[N];
vector<int> getTo[N];

// int check(int v) {
// 	int ret = 0;
// 	for(int i = 0; i < n; i++) {
// 		if(sts[i].count(v) == 0) return INF;

// 	}
// 	return INF;
// }

int main () {
	scanf ("%d %d", &n, &k);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		int qnt = 0;
		while(x) {
			// sts[i].insert(x);
			getTo[x].push_back(qnt++);
			x/=2;
			// all.insert(x);
		}
	}
	int ans = 2e9;
	for(int val = 1; val < N; val++) {
		if(len(getTo[val]) >= k) {
			sort(getTo[val].begin(), getTo[val].end());
			int now = 0;
			for (int i = 0; i < k; i++)
				now += getTo[val][i];
			ans = min(ans, now);
		}
	}
	printf("%d\n", ans);
	// for(int v : all) {
	// 	if
	// }

	return 0;
}
