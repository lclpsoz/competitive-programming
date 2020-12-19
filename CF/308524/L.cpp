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

const int N = 1e3 + 10;
bool dp[N], vis[N];
int n, n1, nn1, n1n1;
bool solve(int a)
{
	if(vis[a]) return dp[a];
	vis[a] = true;
	if(a < n) return dp[a] = false;
	if(a <= nn1) return dp[a] = true;
	dp[a] = false;
	for(int i = a - n1n1; i <= a - n1; i++)
		dp[a] = max(dp[a], !solve(i));
	return dp[a];
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
		cin >> n;
		n1 = n - 1;
		nn1 = n * n1;
		n1n1 = n1 * n1;
		bool gg = false;
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < n; i++)
		{
			int a; cin >> a;
			gg = max(gg, solve(a));
		}

		cout << (gg ? "Alice" : "Bob") << endl;
	}

	return 0;
}
