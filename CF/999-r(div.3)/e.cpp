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

int n, m;
vector<int> adj[MAXN];
int ans = 0;
bool vis[MAXN];
int size[MAXN], link[MAXN];
int qnt[MAXN];

vector<int> bfs (int s) {
	queue<int> q;
	vector<int> vec;
	int visited[MAXN];
	memset (visited, 0, sizeof (visited));
	q.push (s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (visited[v]) continue;
		vec.pb (v);
		visited[v] = true;
		for (int u : adj[v])
			if (!vis[u])
				q.push (u);
	}

	return vec;
}

vector<int> adjj[MAXN];
priority_queue<pair<pii, vector<int>>> pq;

int main ()
{
	int a, b, s;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		scanf ("%d %d", &a, &b);
		adj[a].pb (b);
	}

	vector<int> v = bfs (s);
	int total = n;
	for (int u : v) {
		vis[u] = true;
		total--;
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			v = bfs (i);
			pq.push ({{(int)v.size(), i}, v});
		}
	}

	while (total) {
		int maxi = 0;
		while (vis[pq.top().x.y]) pq.pop();
		v = pq.top().y;
		pq.pop();

		for (int u : v)
		    if (!vis[u]) {
    			vis[u] = true;
    			total--;
		    }
		ans++;
	}
	cout << ans << '\n';

	return 0;
}
