// Union-find with Kurskal's algorithm to minimum spanning tree
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> piii;

const int MAXN = 4e4+10;

int ind[MAXN], size[MAXN];

int find (int x)
{
	while (ind[x] != x)
		x = ind[x];
	return x;
}

void unite (int x, int y)
{
	x = find (x);
	y = find (y);
	if (size[x] > size[y])
		swap (x, y);
	size[y] += size[x];
	ind[x] = y;
}

bool same (int x, int y) {return find(x) == find(y);}

int main ()
{
	int r, c;
	int v, w, p;
	int ans;
	priority_queue<piii, vector<piii>, greater<piii>> cables;

	while (scanf ("%d %d", &r, &c), r || c) {
		while (c--) {
			scanf ("%d %d %d", &v, &w, &p);
			cables.push ({p, {v, w}});
		}

		for (int i = 0; i < r; i++) {
			ind[i] = i;
			size[i] = 1;
		}

		ans = 0;
		while (!cables.empty ()) {
			p = cables.top().first;
			v = cables.top().second.first;
			w = cables.top().second.second;
			cables.pop();
			if (!same(v, w)) {
				ans += p;
				unite (v, w);
			}
		}

		printf ("%d\n", ans);
	}

	return 0;
}
