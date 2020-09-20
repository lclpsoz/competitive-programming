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

const int N = 5e5 + 10;

int n, q;
map<int, int> mp;
int bit[N], c[N];

void add(int p, int v) {
	for(int i = p; i < N; i +=i&-i)
		bit[i] += v;
}

int sum(int p) {
	int ret = 0;
	for(int i = p; i; i-=i&-i)
		ret += bit[i];
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> c[i];

	vector<pair<pii, int>> queries;
	for(int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		queries.push_back({{r, l}, i});
	}
	sort(ALL(queries));
	int lst = 1;
	mp[c[1]] = 1;
	add(1, 1);
	vector<pii> ans;
	for(auto p : queries) {
		int r = p.x.x, l = p.x.y;
		while(lst < r) {
			lst++;
			int val = c[lst];
			if(mp.count(val))
				add(mp[val], -1);
			add(lst, 1);
			mp[val] = lst;
		}
		ans.push_back({p.y, sum(r) - sum(l-1)});
	}
	sort(ALL(ans));
	for(auto p : ans)
		cout << p.y << '\n';

	return 0;
}
