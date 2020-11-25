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



int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vpii elem(n+2);
		for(int i = 0; i < n; i++) {
			int x, f;
			cin >> x >> f;
			elem[x].x++;
			elem[x].y+=f;
		}
		set<int> base;
		multiset<int> avail;
		for(int i = 1; i <= n; i++)
			base.insert(i);
		for(int i = 1; i <= n; i++)
			if(elem[i].x)
				avail.insert(elem[i].x);
		int mx_candy = 0;
		vi candies;
		while(LEN(avail)) {
			int now = *avail.begin();
			avail.erase(avail.begin());
			if(*base.begin() <= now) {
				auto it = base.lower_bound(now);
				if(it == base.end() or *it > now) --it;
				mx_candy += *it;
				candies.push_back(*it);
				base.erase(it);
			}
		}
		vpii options;
		for(int i = 1; i <= n; i++)
			if(elem[i].x)
				options.push_back({elem[i].x, elem[i].y});
		sort(ALL(options));
		sort(ALL(candies));
		int mx_f = 0;
		while(LEN(candies)) {
			while(LEN(options) and options.back().x >= candies.back()) {
				avail.insert(-options.back().y);
				options.pop_back();
			}
			// cout << "avail.begin() = " << *avail.begin() << '\n';
			mx_f += min(-*avail.begin(), candies.back());
			avail.erase(avail.begin());
			candies.pop_back();
		}
		cout << mx_candy << ' ' << mx_f << '\n';
	}

	return 0;
}
