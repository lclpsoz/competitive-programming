// Probably possible with Dijkstra
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 1e3+10;

int n, hp;
int d, m;
priority_queue<pii, vector<pii>, greater<pii>> pq;
int verif[MAXN];

int main ()
{
	while (~scanf ("%d %d", &n, &hp)) {
		vector<pii> spells;
		while (n--) {
			scanf ("%d %d", &d, &m);
			spells.push_back ({m, d});
		}
		for (int i = 0; i < MAXN; i++) verif[i] = false;

		pq.push ({0, 0});
		// "Dijkstra"
		while (!pq.empty () && pq.top().second < hp) {
			pii aux = pq.top();
			printf("%d %d\n", aux.first, aux.second);
			pq.pop();
			for (pii p : spells)
				pq.push ({aux.first+p.first, aux.second+p.second});
		}

		(pq.empty() || pq.top().second < hp) ? printf ("-1\n") : printf ("%d\n", pq.top().first);
		while (!pq.empty()) pq.pop();
		spells.clear();
	}

	return 0;
}
