#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int n, m;
int u, v, c;
int ans = 0;
bool verif[510];
vector<pii> adj[510];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main ()
{
	scanf ("%d %d", &n, &m);
	while (m--) {
		scanf ("%d %d %d", &v, &u, &c);
		adj[v].push_back ({c, u});
		adj[u].push_back ({c, v});
	}

	if (n == 1)
		printf ("0\n");
	else {
		v = 1;
		for (pii p : adj[1])
			pq.push (p);
		verif[1] = true;
		pii p = pq.top();
		while (verif[p.y] == false || !pq.empty()) {
			verif[p.y] = true;
			ans += p.x;
			for (pii pp : adj[p.y])
				if (!verif[pp.y])
					pq.push (pp);
			if (pq.empty()) break;
			do {
				p = pq.top();
				pq.pop();
			} while (!pq.empty() && verif[p.y]);
		}

		printf ("%d\n", ans);
	}

	return 0;
}
