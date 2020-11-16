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

	map<vi, int> mp;
	int n, m; cin >> n >> m;
	vector<string> b(n);
	for(string& i : b) cin >> i;
	int q; cin >> q;
	vector<vi> a(q, vi(26, 0));
	for(int i = 0; i < q; i++)
	{
		string s; cin >> s;
		for(char c : s) a[i][c - 'A']++;
		mp[a[i]] |= 1 << i;
	}

	vector<vi> cnt(n, vi(m, 0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			{
				vi now(26, 0);
				for(int k = 0; j + k < m; k++)
				{
					now[b[i][j + k] - 'A']++;
					if(mp.count(now))
					{
						for(int z = 0; z <= k; z++)
							cnt[i][j + z] |= mp[now];
					}
				}
			}
			{
				vi now(26, 0);
				for(int k = 0; i + k < n; k++)
				{
					now[b[i + k][j] - 'A']++;
					if(mp.count(now))
					{
						// if(j == 4)
						// 	cout << i << " achei " << bitset<3>(mp[now]) << endl;
						for(int z = 0; z <= k; z++)
							cnt[i + z][j] |= mp[now];
					}
				}
			}
			{
				vi now(26, 0);
				for(int k = 0; k + i < n && k + j < m; k++)
				{
					now[b[i + k][j + k] - 'A']++;
					if(mp.count(now))
					{
						for(int z = 0; z <= k; z++)
							cnt[i + z][j + z] |= mp[now];
					}
				}
			}
			{
				vi now(26, 0);
				for(int k = 0; i + k < n && j - k >= 0; k++)
				{
					now[b[i + k][j - k] - 'A']++;
					if(mp.count(now))
					{
						for(int z = 0; z <= k; z++)
							cnt[i + z][j - z] |= mp[now];
					}
				}
			}
		}

	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			// if(i == 2)
			// cout << i << ", " << j << ": " << bitset<3>(cnt[i][j]) << endl;
			if(__builtin_popcount(cnt[i][j]) > 1) ans++;
		}

	cout << ans << endl;

	return 0;
}
