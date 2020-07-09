#include <bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int, vector<int>>> piiv;

int adj[17][17];

priority_queue <piiv, vector<piiv>, greater<piiv>> caminhos;

int main ()
{
	int c, e, a, b, x;
	while (scanf ("%d %d", &c, &e), c || e) {
		for (int i = 0; i < e; i++) {
			scanf ("%d %d %d", &a, &b, &x);
			adj[a][b] = adj[b][a] = x;
		}
		scanf ("%d", &a);

		caminhos.push ({0, {a, {a}}});
		piiv aux;
		while (!caminhos.empty()) {
			aux = caminhos.top ();
			//printf ("%d %d\n", aux.first, aux.second);
			if (aux.second.first == 1)
				break;
			caminhos.pop ();
			for (int i = 0; i < 16; i++) {
				if (adj[aux.second.first][i]) {
					piiv aux2;
					aux2.first = aux.first+adj[aux.second.first][i];
					aux2.second.first = i;
					aux2.second.second = aux.second.second;
					aux2.second.second.push_back (i);
					caminhos.push (aux2);
				}
				adj[aux.second.first][i] = 0;
			}
		}
		while (!caminhos.empty())
			caminhos.pop();

		if (aux.first < 120) {
			printf ("Will not be late. Travel time - %d - best way -", aux.first);
			for (int z : aux.second.second)
				printf (" %d", z);
			putchar ('\n');
		} else {
			printf ("It will be %d minutes late. Travel time - %d - best way -", aux.first-120, aux.first);
			for (int z : aux.second.second)
				printf (" %d", z);
			putchar ('\n');
		}

		for (int i = 0; i < 16; i++)
			for (int j = 0; j < 16; j++)
				adj[i][j] = 0;
	}

	return 0;
}
