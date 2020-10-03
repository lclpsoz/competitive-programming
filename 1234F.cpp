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

const int N = 1<<20;

string s;
int dp[N];
vector<int> masks;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> s;

	int l, r;
	int msk_now = 0;
	l = r = 0;
	while(r < LEN(s)) {
		int bit = 1<<(s[r]-'a');
		int bl = l;
		while(msk_now&bit)
			msk_now ^= (1<<(s[l++]-'a'));
		msk_now ^= bit;
		++r;
		int now = msk_now;
		for(int i = l; i < r; i++) {
			dp[now] = r-i;
			now ^= 1<<(s[i]-'a');
		}
		// cout << l << ' ' << r << ": " << bitset<15>(msk_now) << '\n';
	}


	for(int i = 1; i < N; i++)
		masks.push_back(i);

	sort(ALL(masks), [&](int lhs, int rhs) {
		return __builtin_popcount(lhs) < __builtin_popcount(rhs);
	});

	int ans = 0;
	for(int msk : masks) {
		// cout << __builtin_popcount(msk) << ' ' << bitset<20>(msk) << '\n';
		if(dp[msk] == 0)
			for(int i = 0; i < 20; i++) {
				// cout << bitset<5>(msk) << ' ' << i << '\n';
				int bit = 1<<i;
				if(bit&msk)
					dp[msk] = max(dp[msk], dp[msk^bit]);
			}

		int inv_msk = (N-1)^msk;
		ans = max(max(ans, dp[msk]), dp[msk]+dp[inv_msk]);
	}

	cout << ans << '\n';

	return 0;
}
