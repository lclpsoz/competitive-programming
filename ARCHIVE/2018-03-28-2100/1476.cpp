#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int MAXN = 1e4+10, BIG = 1e6;

int n, m, s;
int a, b, w;
vector <pii> adj[MAXN];
int dist[MAXN];
priority_queue <pii> q; //first: weight, second: island
pii aux;

int main ()
{
	while (scanf ("%d %d %d", &n, &m, &s) != EOF) {
		for (int i = 0; i < m; i++) {
			scanf ("%d %d %d", &a, &b, &w);
			adj[a].push_back ({w, b});
			adj[b].push_back ({w, a});
		}
		for (int i = 0; i < s; i++) {
			scanf ("%d %d", &a, &b);
			q.push ({BIG, a});
			while (!q.empty ()) {
				aux = q.top ();
				// printf ("\t%d [%d]\n", aux.second, aux.first);
				q.pop ();
				dist[aux.second] = aux.second;
				if (aux.second == b)
					break;
				for (auto i : adj[aux.second])
					if (dist[i.second] == -1)
						q.push ({min (aux.first, i.first), i.second});
			}
			while (!q.empty ())
				q.pop ();
			printf ("%d\n", aux.first);
		}
	}
	return 0;
}
