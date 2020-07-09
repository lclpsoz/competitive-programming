// The problem is asking the amount of roads
// needed to conenct all main spots of de city.
// Using the logic of "strong connectivity" it's
// possible to solve the problem, I will use
// union find instead of two DFS in this case.
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int link[MAXN], size[MAXN];
bool verif[MAXN];


int find (int x)
{
	while (x != link[x]) x = link[x];
	return x;
}

void unite (int x, int y)
{
	x = find(x);
	y = find(y);
	if (size[x] > size[y]) swap (x, y);
	size[y] += size[x];
	link[x] = y;
}

bool same (int x, int y) {return find(x) == find(y);}

int main ()
{
	int t, n, m;
	int a, b;

	scanf ("%d", &t);
	int ki = 1;
	while (ki <= t) {
		scanf ("%d %d", &n, &m);
		for (int i = 0; i <= n; i++) {
			link[i] = i;
			size[i] = 1;
			verif[i] = false;
		}
		while (m--) {
			scanf ("%d %d", &a, &b);
			if (!same(a,b))
				unite (a, b);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			// printf ("%d: %d\n", i, link[i]);
			if (!verif[link[i]]) {
				verif[link[i]] = true;
				ans++;
			}
		}
		if (ans == 1)
			printf ("Caso #%d: a promessa foi cumprida\n", ki);
		else {
			printf ("Caso #%d: ainda falta(m) %d estrada(s)\n", ki, ans-1);
		}

		ki++;
	}

	return 0;
}
