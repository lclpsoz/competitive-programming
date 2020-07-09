#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int link[MAXN], size[MAXN];

int find (int x)
{
	while (link[x] != x) x = link[x];
	return x;
}

void unite (int x, int y)
{
	x = find (x);
	y = find (y);
	if (size[x] < size[y])
		swap (x, y);
	size[x] += size[y];
	link[y] = x;
}

bool same (int x, int y)
{
	return find (x) == find (y);
}

int main ()
{
	int t, n, m;
	int a, b;
	int ans;
	set<int> conj;

	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {
		ans = 0;
		scanf ("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			size[i] = 1;
			link[i] = i;
		}
		while (m--) {
			scanf ("%d %d", &a, &b);
			if (!same (a, b))
				unite (a, b);
		}

		for (int i = 1; i <= n; i++)
			conj.insert (link[i]);

		ans = conj.size();
		conj.clear();

		printf ("Caso #%d: ", i);
		if (ans == 1)
			printf ("a promessa foi cumprida\n");
		else printf ("ainda falta(m) %d estrada(s)\n", ans-1);
	}

	return 0;
}
