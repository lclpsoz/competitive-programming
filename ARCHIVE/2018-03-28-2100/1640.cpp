// grafo_1: Grafo inicial com todas as cidades
// grafo_2: Grafo final apenas com cidade 1, n e todas as com hotel (e suas conexoes como arestas de peso 1)
// com_hotel: Array onde 'true' quando a cidade possui hotel
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4+5;
typedef pair <int, int> pii;
typedef priority_queue <pii, vector<pii>, greater<pii>> pq_pii;

int n;
vector <pii> grafo_1[MAXN];
vector <int> grafo_2[MAXN];
bool passou[MAXN];
bool com_hotel[MAXN];

// Aplicado primeiro para gerar o grafo_2 somente
// com os caminhos entre cidade 1, n e cidades com
// hotel.
void dijkstra (int c)
{
	pq_pii filap;
	filap.push ({0, c}); // Primeira cidade
	while (!filap.empty ()) {
		pii atual = filap.top ();
		//printf ("%d %d\n", atual.first, atual.second);
		filap.pop ();
		for (auto i : grafo_1[atual.second]) {
			if (i.first + atual.first <= 600) {
				if (i.second != c && !passou[i.second]) {
					filap.push ({i.first+atual.first, i.second});
					if (com_hotel[i.second] || i.second == 1 || i.second == n) {
						grafo_2[i.second].push_back (c);
						grafo_2[c].push_back (i.second);
					}
					passou[i.second] = true;
				}
			}
		}
	}
}

int mini;
int bfs ()
{
	queue<pii> fila;
	int passou[MAXN];
	for (int i = 0; i < MAXN; i++)
		passou[i] = 0;
	fila.push ({0, 1});
	//printf ("===BFS===\n");
	while (!fila.empty ()) {
		pii aux = fila.front ();
		//printf ("%d %d\n", aux.first, aux.second);
		fila.pop ();
		for (auto i : grafo_2[aux.second]) {
			if (i == n)
				return aux.first;
			else if (!passou[i]) {
				fila.push ({aux.first+1, i});
				passou[i] = 1;
			}
		}
	}
	return -1;
}

int main ()
{
	int h, r;
	int x, st, end, t;
	while (scanf ("%d", &n), n) {
		scanf ("%d", &h);
		for (int i = 0; i < h; i++) {
			scanf ("%d", &x);
			com_hotel[x] = true;
		}
		scanf ("%d", &r);
		for (int i = 0; i < r; i++) {
			scanf ("%d %d %d", &st, &end, &t);
			grafo_1[st].push_back ({t, end});
			grafo_1[end].push_back ({t, st});
		}

		dijkstra (1);
		for (int i = 0; i <= n; i++)
			passou[i] = false;
		dijkstra (n);
		for (int i = 0; i < MAXN; i++)
			if (com_hotel[i]) {
				for (int i = 0; i <= n; i++)
					passou[i] = false;
				dijkstra (i);
			}

		printf ("%d\n", bfs ());

		for (int i = 0; i < MAXN; i++) {
			passou[i] = false;
			com_hotel[i] = false;
			grafo_1[i].clear ();
			grafo_2[i].clear ();
		}
	}
}
