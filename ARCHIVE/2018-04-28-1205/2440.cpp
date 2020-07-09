// Counting amount of families with UNION-FIND
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+10;

int size[MAXN], link[MAXN];

int find (int x)
{
	while (x != link[x]) x = link[x];
	return x;
}

bool same (int x, int y)
{
	return find (x) == find (y);
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

int main ()
{
	int n, m, x, y;
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		link[i] = i;
		size[i] = 1;
	}

	while (m--) {
		scanf ("%d %d", &x, &y);
		if (!same (x, y))
			unite (x, y);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (link[i] == i)
			ans++;

	printf ("%d\n", ans);

	return 0;
}
