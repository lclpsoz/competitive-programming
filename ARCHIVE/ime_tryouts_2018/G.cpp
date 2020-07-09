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

const int N = 2e5 + 10, A = 5e5 + 10;

int a[N], cnt[A], dp[A];
vector<int> p[A];
bool is[A];

ll add(int x, int val){
	ll ret = 0;
	for(int mask = 0; mask < (1 << len(p[x])); mask++){
		if(!mask) dp[0] = 1;
		else dp[mask] = dp[mask & (mask - 1)]*p[x][__builtin_ctz(mask)];
		
		int d = dp[mask];
		int mobius = (__builtin_popcount(mask) & 1) ? -1 : 1;
		ret -= mobius*cnt[d]*1LL*(cnt[d] - 1)/2;
		cnt[d] += val;
		ret += mobius*cnt[d]*1LL*(cnt[d] - 1)/2;
	}
	return ret;
}

int main () {
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i = 2; i < A; i++) if(p[i].empty()){
		for(int j = i; j < A; j += i){
			p[j].push_back(i);
		}
	}
	
	ll ans = 0;
	while(q--){
		int x;
		scanf("%d", &x);
		ans += add(a[x], is[x]? -1 : 1);
		is[x] ^= 1;
		printf("%lld\n", ans);
	}
	
	return 0;
}