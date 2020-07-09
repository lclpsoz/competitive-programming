// Using Prim's algorithm to calculate the minimum spanning tree of a graph
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e4+10;

typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;

int m, n;
int a, b, p;
int ans;
vector<pii> adj[MAXN];
bool verif[MAXN];
priority_queue <piii, vector<piii>, greater<piii>> pq;

int main ()
{
	while (scanf ("%d %d", &m, &n), n || m) {
		for (int i = 0; i <= m; i++) {
			verif[i] = false;
			adj[i].clear ();
		}
		while (n--) {
			scanf ("%d %d %d", &a, &b, &p);
			adj[a].push_back ({p, b});
			adj[b].push_back ({p, a});
		}
		for (pii x : adj[0])
			pq.push ({x.first, {0, x.second}});
		verif[0] = true;
		ans = 0;
		while (!pq.empty ()) {
			piii x = pq.top ();
			pq.pop ();
			if (!verif[x.second.second]) {
				ans += x.first;
				for (pii y : adj[x.second.second])
					pq.push ({y.first, {x.second.second, y.second}});
				verif[x.second.second] = true;
			}
		}

		printf ("%d\n", ans);
	}

	return 0;
}
