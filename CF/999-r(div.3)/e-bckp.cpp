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

const int MAXN = 5010;

int n, m, s;
vector<int> adj[MAXN];
int ans = 0;
bool vis[MAXN];
int size[MAXN], link[MAXN];

int find (int a ) {
	while (a != link[a]) a = link[a];
	return a;
}

bool same (int a, int b) {
	return find (a) == find (b);
}

void unite (int a, int b) {
	a = find (a);
	b = find (b);
	if (size[a] > size[b]) swap (a, b);
	size[b] += size[a];
	link[a] = b;
}

int main ()
{
	int a, b;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &a, &b);
		adj[a].pb (b);
	}

	queue<int> q;
	q.push (s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (vis[v]) continue;
		vis[v] = true;
		for (int u : adj[v])
			q.push (u);
	}
	for (int i = 1; i <= n; i++)
		ans += !vis[i];
	cout << ans << '\n';

	return 0;
}
