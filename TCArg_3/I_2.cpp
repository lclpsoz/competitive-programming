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

const int MOD = 1e9 + 7;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

ll n;

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	scanf("%lld", &n);
	string base = "";
	map<string, int> mp;
	for(int i = 0; i < n; i++)
		if(i%2)
			base.push_back('a');
		else
			base.push_back('b');
	
	for(int i = 0; i < (1<<n); i++) {
		string now = "";
		for(int j = 0; j < n; j++)
			if((1<<j)&i)
				now.push_back(base[j]);
		mp[now]++;
	}
	ll ans = 0;
	for(auto p : mp) {
		bool ok = true;
		for(int i = 0; i < LEN(p.x)-1; i++)
			if(p.x[i] == p.x[i+1]) ok = false;
		if(ok) {
			cout << p.x << ' ' << p.y << '\n';
			ans += p.y;
		}
	}

	printf("%lld\n", ans-1);

	return 0;
}
