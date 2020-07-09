#include <bits/stdc++.h>
using namespace std;

char adj[105][105]; // '\0': Bridge can't be used/don't exist | 'e': Bridge can be used | 'l': Bridge is part of a loop
char vert[55]; // i: First vertice | p: Vertice already visited
bool tem_loop;
int a, b, c, p;
int loop;

void imprime_adj ()
{
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= c; j++)
			if (adj[i][j] == '\0')
				printf ("- ");
			else
				printf ("%c ", adj[i][j]);
		putchar ('\n');
	}
}

void dfs (int v)
{
	if (vert[v] == 'i')
		tem_loop = true;
	else
		vert[v] = 'p';

	for (int i = 1; i <= c && !tem_loop; i++) {
		if (adj[v][i] != '\0' && v != i && vert[i] != 'p') {
			dfs (i);
			if (tem_loop && adj[v][i] != 'l') {
				adj[v][i] = adj[i][v] = 'l';
				loop++;
			}
		}
	}
	vert[v] = '\0';
}

int main ()
{
	while (scanf ("%d%d", &c, &p) != EOF) {
		for (int i = 0; i < p; i++) {
			scanf ("%d %d", &a, &b);
			adj[a][b] = adj[b][a] = 'e';
		}

		for (int i = 1; i <= c; i++)
			for (int j = 1; j <= c; j++) {
				if (i != j && adj[i][j] != '\0' && adj[i][j] != 'l') {
					adj[i][j] = '\0';
					adj[j][i] = '\0';
					vert[i] = 'i';
					tem_loop = false;
					dfs (j);
					if (tem_loop) {
						if (adj[i][j] != 'l')
							loop++;
						adj[i][j] = adj[j][i] = 'l';
					}
					else
						adj[i][j] = adj[j][i] = 'e';
					vert[i] = '\0';
				}
			}
		//imprime_adj ();

		for (int i = 1; i <= c; i++)
			for (int j = 1; j <= c; j++)
				adj[i][j] = '\0';

		printf ("%d\n", p-loop);
		loop = 0;

	}

	return 0;
}
