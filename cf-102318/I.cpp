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

const int MAXN = 1e5 + 10;

int n;
ll t[4*MAXN];
int mp[MAXN];

void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

ll sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void upd(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            upd(v*2, tl, tm, pos, new_val);
        else
            upd(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main () {
	ll a[MAXN];
	int q;
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &n);
		for(int i = 0; i < 4*n; i++) t[i] = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			mp[a[i]] = i;
		}
		build(a, 1, 1, n);
		ll ans = min(	sum(1, 1, n, 1, mp[1]-1),
						sum(1, 1, n, mp[1]+1, n) + 1);
		// printf("1: %lld\n", ans);
		upd(1, 1, n, mp[1], 0);
		for(int i = 2; i <= n; i++) {
			int l = mp[i];
			int r = mp[i-1];
			if(l > r) swap(l, r);
			ll betw = sum(1, 1, n, l+1, r-1);
			ll comp = sum(1, 1, n, 1, n) - i - betw;
			if(mp[i] < mp[i-1]) betw += i;
			else comp += i;
			ans += min(betw, comp);
			// printf("%d: %lld\n", i, ans);
			upd(1, 1, n, mp[i], 0);
		}
		printf("%lld\n", ans);
	}

	return 0;
}
