#include<bits/stdc++.h>
using namespace std;

// ----------------
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

// ----------------

const int P = 257, M1 = 1e9 + 7, M2 = 1e9 + 9;
const int N = 1e5 + 10, MS = 1e3 + 10;

int n, m;
char text[N], tmp[MS];
int cost[MS], w1[MS], w2[MS], sz[MS];

int pot1[N], pot2[N], h1[N], h2[N];

void pre(){
	pot1[0] = 1;
	for(int i = 1; i < N; i++){
		pot1[i] = pot1[i - 1]*1LL*P%M1;
	}
	pot2[0] = 1;
	for(int i = 1; i < N; i++){
		pot2[i] = pot2[i - 1]*1LL*P%M2;
	}
}

pair<int, int> get(int l, int r){
	int sz = r - l + 1;
	return {mod(h1[r] - h1[l - 1]*1LL*pot1[sz], M1), mod(h2[r] - h2[l - 1]*1LL*pot2[sz], M2)};
}

ll dp[N];

int main () {
	pre();
	
	scanf("%s", text + 1);
	n = (int)strlen(text + 1);
	
	h1[1] = text[1];
	for(int i = 2; i <= n; i++){
		h1[i] = (h1[i - 1]*1LL*P + text[i])%M1;
	}
	
	h2[1] = text[1];
	for(int i = 2; i <= n; i++){
		h2[i] = (h2[i - 1]*1LL*P + text[i])%M2;
	}
	
	scanf("%d", &m);
	
	for(int i = 1; i <= m; i++){
		scanf("%s %d", tmp + 1, &cost[i]);
		
		sz[i] = (int)strlen(tmp + 1);
		
		w1[i] = tmp[1];
		for(int j = 2; j <= sz[i]; j++){
			w1[i] = (w1[i]*1LL*P + tmp[j])%M1;
		}
		
		w2[i] = tmp[1];
		for(int j = 2; j <= sz[i]; j++){
			w2[i] = (w2[i]*1LL*P + tmp[j])%M2;
		}
	}
	
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		dp[i] = dp[i - 1];
		for(int j = 1; j <= m; j++){
			if(i >= sz[j] && get(i - sz[j] + 1, i) == make_pair(w1[j], w2[j])){
				dp[i] = max(dp[i], dp[i - sz[j]] + cost[j]);
			}
		}
	}
	
	printf("%lld\n", dp[n]);
	
	
	return 0;
}
