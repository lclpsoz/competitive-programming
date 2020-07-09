#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n, m;
int q, a, b;
int link[MAXN];
int size[MAXN];
int power[MAXN];

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
	if (size[x] > size[y])
		swap (x, y);
	size[y] += size[x];
	power[y] += power[x];
	link[x] = y;
}

int main ()
{
	int guild = 1;
	while (scanf ("%d %d", &n, &m), n || m) {
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &a);
			power[i] = a;
			link[i] = i;
			size[i] = 1;
		}
		int ans = 0;
		while (m--) {
			scanf ("%d %d %d", &q, &a, &b);
			if (q == 1) {
				if (!same (a, b))
					unite (a, b);
			}
			else {
				guild = find (1);
				a = find (a);
				b = find (b);
				if (guild == a && power[a] > power[b])
					ans++;
				else if (guild == b && power[b] > power[a])
					ans++;
			}
		}

		printf ("%d\n", ans);
	}

	return 0;
}
