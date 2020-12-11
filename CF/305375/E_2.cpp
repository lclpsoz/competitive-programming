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

const int N = 62;
ll basis[N];
vi ans;
int sz;

void insertVector(ll mask, int n) {
	ll num = mask;
	for (int i = 0; i < n; i++) {
		if ((mask & 1 << i) == 0) continue; // continue if i != f(mask)

		if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
			basis[i] = mask;
			++sz;
			ans.emplace_back(num);
			return;
		}

		mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
	}
}

ll nxt_num (ll v) {
	int base = __builtin_popcountll(v);
	v += (1LL<<__builtin_ctzll(v));
	assert(__builtin_popcountll(v) <= base);
	int need = base - __builtin_popcountll(v);
	v |= (1LL << need)-1;

	// for (int i = 0; need; i++) {
	// 	if (!((1LL<<i)&v)) {
	// 		v |= (1LL<<i);
	// 		--need;
	// 	}
	// }

	return v;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t; cin >> t;
	while(t--)
	{
		ans.clear();
		sz = 0;
		
		int n, k;
		cin >> n >> k;

		for(int i = 0; i < n; i++)
			basis[i] = 0;

		ll v = (1LL << k) - 1;
		while(sz < n)
		{
			cout << v << " " << bitset<26>(v) << endl;
			if(64 - __builtin_clzll(v) > n) break;
			insertVector(v, n);
			v = nxt_num(v);
		}

		if(sz < n) ans = {-1};
		for(int i = 0; i < LEN(ans); i++)
		{
			// cout << ans[i] << ": " << bitset<N>(ans[i]) << endl;
			cout << ans[i] << " \n"[i == LEN(ans) - 1];
		}
	}

	return 0;
}
