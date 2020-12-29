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

struct dsu
{
	vector<int> p, sz;
	int n;
	dsu(){}
	dsu(int t)
	{
		n = t;
		sz.assign(n, 1);
		p.resize(n);
		for(int i = 0; i < n; i++) p[i] = i;
	}
	int find(int i)
	{
		return (p[i] == i ? i : p[i] = find(p[i]));
	}
	bool same(int i, int j)
	{
		return find(i) == find(j);
	}
	bool merge(int i, int j)
	{
		if(!same(i, j))
		{
			i = find(i);
			j = find(j);
			if(sz[i] > sz[j])
				swap(i, j);
			p[i] = j;
			sz[j] += sz[i];
			return true;
		}
		return false;
	}
};

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t; cin >> t;
	while(t--)
	{
		int n, m, k;
		cin >> n >> m >> k;

		vector<tuple<int, int, int>> e1, e2;
		for(int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			--a, --b;
			if(c > k)
				e1.emplace_back(c, a, b);
			else
				e2.emplace_back(c, a, b);
		}

		sort(ALL(e1));
		sort(ALL(e2));
		ll ans = INF<ll>;
		
		dsu uf(n);
		for(auto [c, a, b] : e2)
			uf.merge(a, b);

		if(uf.sz[uf.find(0)] == n)
			ans = min(ans, (ll)k - get<0>(e2.back()));
		
		if(!empty(e1))
		{
			if(uf.sz[uf.find(0)] == n)
				ans = min(ans, get<0>(e1[0]) - (ll)k);
			else
			{
				ll now = 0;
				for(auto [c, a, b] : e1)
					if(uf.merge(a, b)) now += c - k;
				ans = min(ans, now);
			}
		}

		cout << ans << endl;
	}

	return 0;
}
