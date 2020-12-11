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



int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		ll n, m;
		set<ll> rem;
		cin >> n >> m;
		
		ll ans = (1LL<<(m-1)) - 1;
		ll q0, q1;
		q0 = ans, q1=ans+1;
		for(int i = 0; i < n; i++) {
			string s;
			cin >> s;
			ll val = stoll(s, nullptr, 2);
			rem.insert(val);
			if(val == ans) {
				--ans;
				q0--;
				while(rem.count(ans))
					--ans;
			} else if(val < ans)
				q0--;
			else
				q1--;
			if(q0 > q1) {
				--ans;
				q0--;
				q1++;
				while(rem.count(ans))
					--ans;
			}
			if(q1-1 > q0) {
				++ans;
				q1--;
				q0++;
				while(rem.count(ans))
					++ans;

			}
			// cout << "val = " << val << ", ans = " << ans << ", q0, q1 = " << q0 << ' ' << q1 << '\n';
		}
		vector<ll> bits;
		while(ans) {
			bits.push_back(ans%2);
			ans /= 2;
		}
		while(LEN(bits) < m) bits.push_back(0LL);
		reverse(ALL(bits));
		for(ll v : bits)
			cout << v;
		cout << '\n';
		
		// const int q_bits = 64-__builtin_clzl(ans);
		// cout << (bitset<q_bits>(ans)) << '\n';
	}

	return 0;
}
