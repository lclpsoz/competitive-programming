#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+10;
typedef pair<int,int> pii;

int n, m, k;
double p;
int a, b;
vector<int> adj[MAXN];
int soldiers[MAXN];
bool verif[MAXN];

double pot (double x, int y)
{
	double r = 1;
	while (y-- && r > 0.0004)
		r *= x;
	return r;
}

double dijkstra (int st, int en)
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push ({soldiers[st], st});
	while (!pq.empty () && pq.top().second != en) {
		int s = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		for (int x : adj[v]) {
			if (!verif[x]) {
				pq.push ({s+soldiers[x], x});
				verif[x] = true;
			}
		}
	}

	if (pq.empty() || pq.top().first > k)
		return 0.0;
	return pot (p, pq.top ().first);
}

int main ()
{
	while (scanf ("%d %d %d %lf", &n, &m, &k, &p) != EOF) {
		for (int i = 0; i < MAXN; i++) {
			adj[i].clear ();
			soldiers[i] = 0;
			verif[i] = false;
		}
		while (m--) {
			scanf ("%d %d", &a, &b);
			adj[a].push_back (b);
			adj[b].push_back (a);
		}
		scanf ("%d", &m);
		while (m--) {
			scanf ("%d", &a);
			soldiers[a]++;
		}
		int st, en;
		scanf ("%d %d", &st, &en);
		printf ("%0.3lf\n", dijkstra (st, en));
	}

	return 0;
}
