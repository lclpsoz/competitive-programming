#include <bits/stdc++.h>
using namespace std;

// ------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

// ------------

const int NL = 1e5 + 10, MAX = 2e5 + 10;

int n, l;
vector<pair<int, int>> pos[MAX];
set<pair<int, int>> heap[MAX];
int dp[NL];

int main () {
	scanf("%d %d", &n, &l);
	for(int i = 0; i < n; i++){
		int x, y;
		scanf("%d %d", &x, &y); y += 1000;
		pos[x + y].push_back({y - x + 1e5 + 10, i});
		dp[i] = 1;
	}
	
	int ans = 0;
	for(int x = MAX - 1; x >= 0; x--){
		
		int last = min(x + 5, MAX - 1);
		for(int x2 = x + 1; x2 <= last; x2++){
			for(auto tmp : pos[x2]){
				int y = tmp.x, idx = tmp.y;
				if()
			}
		}
	}
	printf("%d\n", ans);
	
	
	return 0;
}