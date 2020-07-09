#include <bits/stdc++.h>
using namespace std;

const int MAXN = 22;

bool matAdj[MAXN][MAXN];
char vert[MAXN];

void space (int s)
{
	for (int i = 0; i < s; i++) {
		putchar (' ');
		putchar (' ');
	}
}
void dfs (int v, int t)
{
	if (vert[v] == 'w')
		vert[v] = 'b';
	if (vert[v] == 'g') {
		vert[v] = 'b';
		for (int i = 0; i < MAXN; i++) {
			if (matAdj[v][i]) {
				space (t);
				printf ("%d-%d", v, i);
				if (vert[i] != 'b')
					printf (" pathR(G,%d)", i);
				putchar ('\n');

				dfs (i, t+1);
			}
		}
		if (t == 1)
			putchar ('\n');
	}
}

int main ()
{
	int n, v, e, a, b;

	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MAXN; j++) {
			vert[j] = 'w';
			for (int k = 0; k < MAXN; k++)
				matAdj[j][k] = false;
		}

		printf ("Caso %d:\n", i+1);
		scanf ("%d %d", &v, &e);
		for (int j = 0; j < e; j++) {
			scanf ("%d %d", &a, &b);
			matAdj[a][b] = true;
			vert[a] = 'g';
		}

		for (int j = 0; j <= v; j++)
			if (vert[j] == 'g')
				dfs (j, 1);

	}

	return 0;
}
