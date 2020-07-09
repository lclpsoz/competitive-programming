#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

using pp = pair<pii, ld>;
const int N = 1e3+100;

int n, m;
map<string, int> mp;
vector<pp> points[N];
vector<int> adj[N];

inline ld dist (pii &p1, pii &p2) {
	pii p = {abs (p1.x-p2.x), abs (p1.y-p2.y)};
	return sqrtl (p.x*p.x + p.y*p.y);
}

void solve (int v, int parent) {
	for (int u : adj[v])
		if (u != parent)
			solve (u, v);

	for (auto &p : points[v]) {
		for (int u : adj[v]) {
			if (u == parent) continue;
			ld now = 1e18;
			for (pp &p2 : points[u])
				now = min (now, dist (p.x, p2.x)+p2.y);
			p.y += now;
		}
	}
}

int main () {
	cin.tie (0); cout.tie (0);
	ios::sync_with_stdio (false);
	cout << fixed;
	cout << setprecision (1);
	
	while (cin >> n, n) {
		mp.clear();
		for (int i = 1; i <= n; i++) {
			points[i].clear();
			adj[i].clear();
		}
		
		for (int i = 1; i <= n; i++) {
			string str;
			cin >> str >> m;
			mp[str] = i;
			
			for (int j = 0; j < m; j++) {
				int x, y;
				cin >> x >> y;
				points[i].push_back ({{x, y}, 0.0});
			}
		}
		
		for (int i = 1; i < n; i++) {
			string str1, str2;
			cin >> str1 >> str2;
			int a, b;
			a = mp[str1], b = mp[str2];
			adj[a].push_back (b);
			adj[b].push_back (a);
		}
		
		solve (1, 1);
		ld ans = 1e18;
		for (pp p : points[1])
			ans = min (ans, p.y);
		
// 		for (int i = 1; i <= n; i++) {
// 			cout << "Vert " << i << '\n';
// 			for (auto p : points[i])
// 				cout << "    (" << p.x.x << ", " << p.x.y << "): " << p.y << '\n';
// 		}
		
		cout << ans << '\n';
	}

	return 0;
}
