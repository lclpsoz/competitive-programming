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

const int N = 1e3 + 10;
char mat[N][N];
int dist[N][N];

using node = pair<int, pii>;
priority_queue<node, vector<node>, greater<node>> pq;

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, m, v;
	cin >> n >> m >> v;
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> mat[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			dist[i][j] = INF<int>;

	dist[x1][y1] = 0;
	pq.emplace(0, pii(x1, y1));

	while(!empty(pq))
	{
		auto [d, p] = pq.top();
		pq.pop();
		auto [i, j] = p;

		if(dist[i][j] != d) continue;

		// cout << i << " " << j << ": " << d << endl;

		if(i == x2 && j == y2)
		{
			cout << "Hello, Deimos!" << endl;
			return 0;
		}

		if(d == v && mat[i][j] == '.') continue;


		if(i - 1 > 0)
		{
			if(mat[i - 1][j] == '.' && d + 1 <= v && d + 1 < dist[i - 1][j])
			{
				dist[i - 1][j] = d + 1;
				pq.emplace(dist[i - 1][j], pii(i - 1, j));
			}
			else if(mat[i - 1][j] == 'F' && dist[i - 1][j])
			{
				dist[i - 1][j] = 0;
				pq.emplace(dist[i - 1][j], pii(i - 1, j));
			}
		}
		if(j - 1 > 0)
		{
			if(mat[i][j - 1] == '.' && d + 1 <= v && d + 1 < dist[i][j - 1])
			{
				dist[i][j - 1] = d + 1;
				pq.emplace(dist[i][j - 1], pii(i, j - 1));
			}
			else if(mat[i][j - 1] == 'F' && dist[i][j - 1])
			{
				dist[i][j - 1] = 0;
				pq.emplace(dist[i][j - 1], pii(i, j - 1));
			}
		}
		if(i + 1 <= n)
		{
			if(mat[i + 1][j] == '.' && d + 1 <= v && d + 1 < dist[i + 1][j])
			{
				dist[i + 1][j] = d + 1;
				pq.emplace(dist[i + 1][j], pii(i + 1, j));
			}
			else if(mat[i + 1][j] == 'F' && dist[i + 1][j])
			{
				dist[i + 1][j] = 0;
				pq.emplace(dist[i + 1][j], pii(i + 1, j));
			}
		}
		if(j + 1 <= m)
		{
			if(mat[i][j + 1] == '.' && d + 1 <= v && d + 1 < dist[i][j + 1])
			{
				dist[i][j + 1] = d + 1;
				pq.emplace(dist[i][j + 1], pii(i, j + 1));
			}
			else if(mat[i][j + 1] == 'F' && dist[i][j + 1])
			{
				dist[i][j + 1] = 0;
				pq.emplace(dist[i][j + 1], pii(i, j + 1));
			}
		}
	}

	cout << "Dire victory" << endl;

	return 0;
}