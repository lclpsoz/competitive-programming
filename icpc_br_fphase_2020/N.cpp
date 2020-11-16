#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ull = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////
using u64 = uint64_t;
using u128 = __uint128_t;
const int N = 1e7;

int lp[N], div_lp[N];
vi pr;
vector<pii> adj[1010];

ll mdc(ll a, ll b) {
	if(b == 0) return a;
	return mdc(b, a%b);
}

ll pollard(ll n) {
	int i = 0, k = 2, d;
	u128 x = 3, y = 3;
	while(++i) {
		x = ((x*x)%n + n - 1)%n;
		u128 ax = 0;
		if(y > x)
			ax = y-x;
		else
			ax = x-y;
		d = mdc(ax, n);
		if(d != 1 and d != n) return d;
		if(i == k) y = x, k*=2;
	}
}

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(ll n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	for(int i =  2; i < N; i++) {
		if(lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j] < N; ++j)
	        lp[i * pr[j]] = pr[j];
	}
	// cout << LEN(pr) << '\n';

	int n, m, k;
	cin >> m >> n >> k;
	vector<ll> vals_n(n+10);
	vector<ll> ans(m+10);
	for(int i = 1; i <= n; i++) {
		ll x;
		cin >> vals_n[i];
		// vector<ll> prs = factorization(x);
		// for(ll y : prs)
		// 	ans.insert(y);
	}

	while(k--) {
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back({v, d});
	}

	int lst_pr = 0;
	for(int i = 1; i <= m; i++) {
		ll val = vals_n[adj[i][0].x];
		while(lst_pr < LEN(pr) and val%pr[lst_pr])
			lst_pr++;
		if(lst_pr == LEN(pr)) {
			if(MillerRabin(val))
				ans[i] = val;
			else {
				ll ax = pollard(val);
				val /= ax;
				ans[i] = min(val, ax);
				assert(MillerRabin(val) and MillerRabin(ax));
			}
		} else
			ans[i] = pr[lst_pr];
		for(pii p : adj[i]) {
			int u = p.x;
			int qnt = 0;
			while(vals_n[u]%ans[i] == 0) {
				vals_n[u] /= ans[i];
				qnt++;
			}
			assert(qnt == p.y);
		}
	}

	for(int i = 1; i <= m; i++)
		cout << ans[i] << " \n"[i==m];

	return 0;
}
