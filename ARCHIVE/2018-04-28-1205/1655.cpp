#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
typedef pair<double, int> pdi;

int n, m;
int a, b;
double p;
vector<pdi> adj[MAXN];
bool verif[MAXN];

double dijkstra ()
{
	priority_queue<pdi> pq;
	pq.push ({1.0, 1});
	while (!pq.empty () && pq.top().second != n) {
		a = pq.top().second;
		p = pq.top().first;
		pq.pop();
		//printf ("%d %lf\n", a, p);
		if (verif[a]) continue;
		verif[a] = true;
		for (pdi x : adj[a])
			pq.push ({p*x.first, x.second});
	}
	
	return pq.top().first*100;
}

int main ()
{
	while (scanf ("%d", &n), n) {
		for (int i = 1; i <= 100; i++) {
			adj[i].clear();
			verif[i] = false;
		}
		scanf ("%d", &m);
		while (m--) {
			scanf ("%d %d %lf", &a, &b, &p);
			p/=100;
			adj[a].push_back ({p, b});
			adj[b].push_back ({p, a});
		}
		
		printf ("%0.6lf percent\n", dijkstra());
	}

	return 0;
}
