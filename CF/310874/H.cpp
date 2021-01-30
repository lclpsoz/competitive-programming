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

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5 + 10;
bool is_composite[N];
int mobius[N];

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);
	
	vi prime;
	mobius[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (!is_composite[i]) prime.push_back (i), mobius[i] = -1;
		for (int j = 0; j < LEN(prime) && i * prime[j] < N; ++j) {
			is_composite[i * prime[j]] = true;
			mobius[i * prime[j]] = -mobius[i];
			if (i % prime[j] == 0){ mobius[i * prime[j]] = 0; break;}
		}
	}

	int tt; cin >> tt;
	while(tt--)
	{
		int n, m, q;
		cin >> n >> m >> q;
		vi cnt(m + 1, 0);
		for(int i = 0; i < n; i++)
		{
			int a; cin >> a;
			cnt[a]++;
		}

		vector<ll> ans(m + 1, 0);
		for(int x = 1; x <= m; x++)
		{
			for(int d = 1; d <= m / x; d++)
			{
				ll sum = 0;
				for(int a = d; a <= m / x; a += d)
					sum += cnt[a * x];
				ans[x] += mobius[d] * sum * sum;
			}
		}

		while(q--)
		{
			int x; cin >> x;
			cout << ans[x] << '\n';
		}
	}

	return 0;
}
