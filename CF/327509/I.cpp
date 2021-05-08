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

int n;
bool can[3][402][402]; // 1->2, 2->3, 3->1

void solve (vi &t1, vi &t2, vi &dist, bool mat[402][402]) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			vector<pair<ll, ll>> interv(n+1);
			int now = i;
			ll tm = 0;
			// cerr << "i = " << i << '\n';
			for (int k = 1; k <= n; k++) {
				interv[now].x = tm;
				tm += t1[now-1];
				interv[now].y = tm;
				tm += dist[now-1];
				now++;
				if (now == n+1)
					now = 1;
			}
			// for (int k = 1; k <= n; k++)
			// 	cerr << '\t' << k << ": " << interv[k].x << ' ' << interv[k].y << '\n';

			now = j;
			tm = 0;
			bool possible = true;
			// cerr << "j = " << j << '\n';
			for (int k = 1; possible and k <= n; k++) {
				// cerr << "\t" << now << ": " << tm;
				if (tm < interv[now].y) {
					tm += t2[now-1];
					if (tm > interv[now].x) {
						possible = false;
						// cerr << ' ' << tm << '\n';
						break;
					}
				}
				else
					tm += t2[now-1];
				// cerr << ' ' << tm << '\n';

				tm += dist[now-1];
				now++;
				if (now == n+1)
					now = 1;
			}
			// cerr << i << ' ' << j << ' ' << possible << '\n';
			mat[i][j] = possible;
		}
	// cerr << '\n';
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n;
	vi dist(n);
	for (int &x : dist)
		cin >> x;
	
	vi a(n), b(n), c(n);
	for (int &x : a)
		cin >> x;
	for (int &x : b)
		cin >> x;
	for (int &x : c)
		cin >> x;
	solve (a, b, dist, can[0]);
	solve (b, c, dist, can[1]);
	solve (c, a, dist, can[2]);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (can[0][i][j] and can[1][j][k] and can[2][k][i]) {
					cout << i << ' ' << j << ' ' << k << '\n';
					exit(0);
				}
	cout << "impossible" << '\n';


	return 0;
}
