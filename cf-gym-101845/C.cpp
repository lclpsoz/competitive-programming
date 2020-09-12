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

const int N = 130;
int dist[N][N];
string s, t;
int m;

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);

	for(int i = 33; i <= 126; i++)
		for(int j = 33; j <= 126; j++)
			dist[i][j] = (int)1e9;
	for(int i = 33; i <= 126; i++)
		dist[i][i] = 0;

	cin >> s >> t >> m;

	while(m--)
	{
		char a, b;
		int c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	for(int k = 33; k <= 126; k++)
		for(int i = 33; i <= 126; i++)
			for(int j = 33; j <= 126; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int ans = 0;
	for(int i = 0; i < LEN(s); i++)
	{
		if(dist[s[i]][t[i]] >= (int)1e9)
		{
			cout << -1 << endl;
			return 0;
		}
		ans += dist[s[i]][t[i]];
	}
	
	cout << ans << endl;

	return 0;
}
