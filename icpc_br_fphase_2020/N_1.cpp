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

vector<ll> normal_fact(ll x) {
	vector<ll> ret;
	for(int p : pr) {
		if(p*1LL*p > x) break;
		while(x%p == 0) {
			if(LEN(ret) == 0 or ret.back() != p)
				ret.push_back(p);
			x/=p;
		}
	}
	if(x > 1)
		ret.push_back(x);
	return ret;
}

vector<ll> factorization(ll x) {
	vector<ll> ret;
	while(x >= (N*1ll*N-100)) {
		ll fct = pollard(x);
		x /= fct;
		if(fct > x)
			swap(fct, x);
		vector<ll> now = normal_fact(fct);
		for(ll val : now)
			ret.push_back(val);
	}
	if(x > 1) {
		vector<ll> now = normal_fact(x);
		for(ll val : now)
			ret.push_back(val);
	}

	return ret;
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
		adj[v].push_back({u, d});
	}

	for(int i = 1; i <= n; i++) {
		int total_prs = 0;
		for(int j = 0; j < LEN(adj[i]); j++)
			if(ans[adj[i][j].x]) {
				while(vals_n[i]%ans[adj[i][j].x] == 0)
					vals_n[i] /= ans[adj[i][j].x];
				total_prs++;
			}
		if(vals_n[i] > 1) {
			vector<ll> prs = factorization(vals_n[i]);
			sort(ALL(prs));
			prs.resize(unique(prs.begin(), prs.end()) - prs.begin());
			sort(ALL(adj[i]));
			assert((total_prs+LEN(prs)) == LEN(adj[i]));
			for(int j = 0, k = 0; j < LEN(prs); j++) {
				while(ans[adj[i][k].x] != 0) ++k;
				ans[adj[i][k].x] = prs[j];
			}
		}
		// for(int i = 1; i <= m; i++)
		// 	cout << ans[i] << " \n"[i==m];
		// cout.flush();
	}

	// vector<ll> ax;
	// for(ll x : ans)
	// 	ax.push_back(x);
	for(int i = 1; i <= m; i++)
		cout << ans[i] << " \n"[i==m];

	return 0;
}
