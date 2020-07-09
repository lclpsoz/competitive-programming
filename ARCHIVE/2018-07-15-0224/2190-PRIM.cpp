// Prim's (AC SPOJ // WA 10% URI)
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

typedef pair<int, pii> piii;

int n, m;
bool vis[110];
vector<pii> adj[110];
priority_queue<piii, vector<piii>, greater<piii>> pq;
vector<piii> ans;

bool compare (piii a, piii b) {
	return a.x < b.x;
}

int main ()
{
	int cot = 1;
	int a, b, w;
	while (scanf ("%d %d", &n, &m), n) {
		ans.clear();
		for (int i = 1; i <= n; i++) {
			vis[i] = false;
			adj[i].clear();
		}
		while (m--) {
			scanf ("%d %d %d", &a, &b, &w);
			adj[a].pb ({w, b});
			adj[b].pb ({w, a});
		}
		// Add 1:
		for (pii p : adj[1])
			pq.push ({p.x, {1, p.y}});
		vis[1] = true;
		while (!pq.empty()) {
			int w = pq.top().x;
			pii ar = pq.top().y;
			// cout << ": " << ar.x << ' ' << ar.y << '\n';
			pq.pop();
			if (vis[ar.y]) continue;
			ans.pb ({w, ar});
			vis[ar.y] = true;
			for (pii p : adj[ar.y])
				pq.push ({p.x, {ar.y, p.y}});
		}

		sort (ans.begin(), ans.end(), compare);
		printf ("Teste %d\n", cot++);
		for (piii p : ans) {
			if (p.y.x > p.y.y) swap (p.y.x, p.y.y);
			printf ("%d %d\n", p.y.x, p.y.y);
		}
		putchar ('\n');

	}

	return 0;
}
