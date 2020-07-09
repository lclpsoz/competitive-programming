#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+10;

int n;
char c;
int size[MAXN], link[MAXN];

int find (int x)
{
	while (x != link[x])
		x = link[x];
	return x;
}

bool same (int x, int y)
{
	return find(x) == find(y);
}

void unite (int x, int y)
{
	x = find (x);
	y = find (y);
	if (size[x] > size[y])
		swap (x, y);
	size[y] += size[x];
	link[x] = y;
}

int main ()
{
	scanf ("%d ", &n);
	for (int i = 1; i <= n; i++) {
		size[i] = 1;
		link[i] = i;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i > j)
				if (getchar () == '1' && !same (i, j))
					unite (i, j);
			else
				getchar ();
			getchar (); //' ' or '\n'
		}
	int qnt_tanks = 0;
	for (int i = 1; i <= n; i++) {
		printf ("link[%d] = %d\n", i, link[i]);
		if (link[i] == i)
			qnt_tanks++;
	}

	qnt_tanks <= 2 ? printf ("Bazinga!\n") : printf ("Fail!\n");

	return 0;
}
