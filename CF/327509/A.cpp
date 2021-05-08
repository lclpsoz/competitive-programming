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

void brute (int n) {
	int m = 10;
	vector<set<vi>> all_cases(m);
	for (int i = 0; i < n; i++) {
		vi now(n);
		now[i] = 1;
		all_cases[i].insert(now);
	}
	for (int i = n; i < m; i++)
		for (int j = 0; j <= i-j-1; j++) {
			int lft = j, rig = i-j-1;
			bool inserted = false;
			for (const vi &vec_lft : all_cases[lft])
				for (const vi &vec_rig : all_cases[rig]) {
					vi now(n);
					for (int k = 0; k < n; k++)
						now[k] = vec_lft[k] + vec_rig[k];
					if (!all_cases[i].count(now)) {
						inserted = true;
						all_cases[i].insert(now);
					}
				}
			if (inserted)
				cerr << "insert in " << i << ": " << lft << ' ' << rig << '\n';
		}
	for (int i = 0; i < m; i++) {
		cerr << i << ": ";
		for (const vi &vec : all_cases[i]) {
			cerr << "(";
			for (int j = 0; j < n; j++)
				cerr << vec[j] << vector<string>({", ", ")"})[j==n-1];
		}
		cerr << '\n';
	}
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, q;
	cin >> n >> q;
	// brute(n);

	vi a(n + 1, 0);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	int nn = n * n;
	vector<ll> dp(nn + 1, 0);
	vector<ll> dp2(nn + 1, 0);
	for(int i = 1; i <= nn; i++)
	{
		dp[i] = INF<ll> + 10;
		for(int j = 1; j <= n; j++)
			dp[i] = min(dp[i], dp[i - j] + a[j]);
	}

	for(int i = 1; i <= n; i++)
		dp2[i] = a[i];
	for(int i = n + 1; i <= nn; i++)
	{
		dp2[i] = INF<ll> + 10;
		for(int j = 1; j <= n; j++)
			dp2[i] = min(dp2[i], dp2[i - j] + a[j]);
		
		// cout << i << ": " << dp2[i] << endl;
	}
	// for(int i = 2*n + 1; i <= nn; i++)
	// 	assert(dp2[i] == dp2[2*n] + dp[i - 2*n]);

	while(q--)
	{
		int k; cin >> k;
		if(k <= nn)
		{
			cout << dp2[k] << '\n';
		}
		else
		{
			ll d = k - nn;
			ll ans = INF<ll> + 10;
			for(int i = 0; i <= n; i++)
				ans = min(ans, a[i] + dp2[nn - i] + dp[nn] * (d / nn) + dp[k % nn]);

			cout << ans << '\n';
		}
	}

	return 0;
}
