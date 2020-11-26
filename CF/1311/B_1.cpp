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

const int N = 110;

int t, n, m;
int a[N];
vector<pii> vec;
bitset<N> p;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
	cin >> t;
	while(t--) {
		p.reset();
		cin >> n >> m;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			vec.push_back({a[i], i});
		}
		for(int i = 1; i <= m; i++) {
			int x;
			cin >> x;
			p[x] = 1;
		}
		sort(vec.begin(), vec.end());
		bool ans = true;
		for(int i = 0; ans and i < n; i++) {
			int target = vec[i].y;

			int l = i, r = target;
			while(l < target and 
					l < LEN(vec)-1 and vec[l+1].x == vec[l].x) ++l;
			while(l > target and 
					l and vec[l-1].x == vec[l].x) --l;
			++l; // 1-indexed
			cout << l << ' ' << r << '\n';
			if(l > r) swap(l, r);
			for(int j = l; ans and j < r; j++)
				if(!p[j])
					ans = false;
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}

	return 0;
}
