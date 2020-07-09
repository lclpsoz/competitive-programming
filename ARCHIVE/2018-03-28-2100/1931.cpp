#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;

typedef pair<long long, long> pii;
typedef pair<long long, pii> piii;

int c, v;
int a, b, p, q;
vector<pii> adj[MAXN];
priority_queue<piii, vector<piii>, greater<piii>> pq;

int main ()
{
	scanf ("%d %d", &c, &v);
	while (v--) {
		scanf ("%d %d %d", &a, &b, &p);
		adj[a].push_back ({b, p});
		adj[b].push_back ({a, p});
	}

	pq.push ({0, {0, 1}});
	printf ("weight\tqnt\tvert\tpq_size\n");
	while (!pq.empty () && (pq.top().second.second != c || pq.top().second.first & 1)) {
		p = pq.top().first;
		q = pq.top().second.first;
		a = pq.top().second.second;
		printf ("%d\t%d\t%d\t%d\n", p, q, a, pq.size());
		pq.pop ();
		for (auto i = adj[a].begin(); i <  adj[a].end(); i++) {
			pii x = *i;
			pq.push ({p+x.second, {q+1, x.first}});
			adj[a].erase (i);
		}
	}
	if (pq.empty ())
		printf ("-1\n");
	else
		printf ("%lld\n", pq.top().first);

	return 0;
}
