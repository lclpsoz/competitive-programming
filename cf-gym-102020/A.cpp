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

const int N = 1e4 + 10, M = 110;
string t;
int n, m, k, dp[N][M][11];
vi z[11];
int pi[M], pre[M][11];

void prefix_function()
{
	for(int i = 1, j = 0; i < m; i++)
	{
		while(j && t[i] != t[j]) j = pi[j - 1];
		if(t[i] == t[j]) ++j;
		pi[i] = j;
	}
}

int add(int a, int b)
{
	return (a + b) % MOD; 
}

int solve(int i, int j, int p)
{
	if(m && j == m) return 0;
	if(i == n) return 1;

	int& ans = dp[i][j][p];

	if(ans == -1)
	{
		ans = 0;
		for(int x : z[p])
			ans = add(ans, solve(i + 1, pre[j][x], x));
	}

	return ans;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	z[0] = {4, 6};
	z[1] = {6, 8};
	z[2] = {9, 7};
	z[3] = {4, 8};
	z[4] = {0, 3, 9};
	z[5] = {};
	z[6] = {0, 1, 7};
	z[7] = {2, 6};
	z[8] = {1, 3};
	z[9] = {2, 4};

	cin >> n >> m >> k >> t;
	prefix_function();

	for(int j = 0; j < m; j++)
		for(int i = 0; i < 10; i++)
		{
			char c = char('0' + i);
			int y = j;
			while(y && t[y] != c) y = pi[y - 1];
			if(t[y] == c) y++;
			pre[j][i] = y;
		}

	memset(dp, -1, sizeof dp);
	cout << solve(0, 0, k) << endl;

	return 0;
}
