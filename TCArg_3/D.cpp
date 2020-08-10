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

const int N = 3e5 + 10;
map<int, int> mp[N];
pii a[N];
vi b[N];
ordered_set<pii> st;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, p;
	cin >> n >> p;

	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		--x, --y;
		b[x].emplace_back(i);
		b[y].emplace_back(i);
		a[i] = {x, y};
	}

	for(int i = 0; i < n; i++)
	{
		for(int j : b[i])
		{
			auto [x, y] = a[j];
			if(y == i) swap(x, y);
			mp[i][y]++;
		}
	}

	for(int i = 0; i < n; i++)
		st.insert({LEN(b[i]), i});

	ll ans = 0;

	for(int i = 0; i < n; i++)
	{
		// cout << "===============" << endl;
		st.erase({LEN(b[i]), i});

		for(auto [x, y] : mp[i])
		{
			st.erase({LEN(b[x]), x});
			st.insert({LEN(b[x]) - y, x});
		}

		// for(auto [x, y] : st) cout << x << ", " << y + 1 << endl;
		ll now = st.order_of_key({p - LEN(b[i]), -1});
		ans += n - now - 1;
		st.insert({LEN(b[i]), i});

		// cout << i + 1 << ": " << n - now - 1 << endl;

		for(auto [x, y] : mp[i])
		{
			st.erase({LEN(b[x]) - y, x});
			st.insert({LEN(b[x]), x});
		}
	}

	cout << ans / 2 << endl;

	return 0;
}
