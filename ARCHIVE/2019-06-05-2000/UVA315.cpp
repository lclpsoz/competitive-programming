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

const int N = 105;

int n;
vector<int> adj[N];
int tNow[N], tLow[N];
bool art[N];
int qnt;

void dfs (int &tim, int v = 1, int p = 1) {
	tNow[v] = tLow[v] = tim++;
//  	cout << v << ' ' << p << '\n';
	for (int u : adj[v]) {
		if (u == 1)
			qnt++;
		if (tNow[u] == -1) {
			dfs (tim, u, v);
			tLow[v] = min (tLow[v], tLow[u]);
			if (tNow[v] <= tLow[u])
				art[v] = true;
		} else if (u != p)
			tLow[v] = min (tLow[v], tNow[u]);
	}
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	while (cin >> n, n) {
		for (int i = 1; i <= n; i++)
			adj[i].clear(), tNow[i] = -1, art[i] = false;
		int v;
		while (cin >> v, v) {
			string line;
 			cin.ignore ();
			getline (cin, line);
// 			cout << line << '\n';
			istringstream is (line);
			int u;
			while (is >> u) {
				if (u == v) continue;
				adj[u].push_back (v);
				adj[v].push_back (u);
			}
		}
		
		int tim = 0;
		dfs (tim);
		int ans = 0;
		for (int i = 2; i <= n; i++)
			ans += art[i];
		int base = tLow[adj[1][0]];
		for (int i = 1; i < len (adj[1]); i++)
			if (tLow[adj[1][i]] != base) {
				++ans;
				break;
			}
			
		cout << ans << '\n';
	}

	return 0;
}
