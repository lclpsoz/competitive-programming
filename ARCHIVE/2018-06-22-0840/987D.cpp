#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 1e5+100;

int n, m, k, s;
deque<pair<pii, int>> q;
vector<int> adj[MAXN];
bool vis[MAXN][105];
int qnt[MAXN];
int ans[MAXN];

int main ()
{
	int x, a, b;
	scanf ("%d %d %d %d", &n, &m, &k, &s);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &x);
		q.pb ({{i, x}, 0});
	}
	while (m--) {
		scanf ("%d %d", &a, &b);
		adj[a].pb (b);
		adj[b].pb (a);
	}

	while (!q.empty()) {
		pair<pii, int> v = q.front(); q.pop_front();
		if (!vis[v.x.x][v.x.y]) {
			vis[v.x.x][v.x.y] = true;
			if (qnt[v.x.x] < s) {
				qnt[v.x.x]++;
				ans[v.x.x]+=v.y;
			}
			for (int u : adj[v.x.x])
				q.pb ({{u, v.x.y}, v.y+1});
		}
	}
	for (int i = 1; i <= n; i++)
		printf ("%d ", ans[i]);
	putchar ('\n');

	return 0;
}
