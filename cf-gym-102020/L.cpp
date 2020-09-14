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

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const ll INF = 1e18;
const int N = 1e4 + 10, Q = 2e5 + 10;
int v[N], w[N], e[N], p[N], n;
int t[Q], k[Q], pq[Q], q;
ll ansq[Q], dp_old[N], dp_new[N];
vi que[N];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n >> q;

	for(int i = 0; i < n; i++)
	{
		cin >> v[i] >> w[i] >> e[i];
		p[i] = i;
	}

	sort(p, p + n, [&](int i, int j){ return e[i] < e[j];});

	int mx = 0;
	for(int i = 0; i < q; i++)
	{
		cin >> t[i] >> k[i];
		pq[i] = i;
		mx = max(mx, k[i]);
	}

	sort(pq, pq + q, [&](int i, int j){ return t[i] < t[j];});
	
	for(int i = 0, j = 0; j < q; j++)
	{
		while(i < n && e[p[i]] <= t[pq[j]]) i++;
		que[i].emplace_back(pq[j]);
	}

	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = 0; j <= mx; j++)
		{
			dp_new[j] = dp_old[j];
			if(j >= w[p[i]])
				dp_new[j] = max(dp_new[j], dp_old[j - w[p[i]]] + v[p[i]]);
		}

		for(int id : que[i])
			ansq[id] = dp_new[k[id]];
		
		swap(dp_new, dp_old);
	}

	for(int i = 0; i < q; i++)
		cout << ansq[i] << '\n';

	return 0;
}
