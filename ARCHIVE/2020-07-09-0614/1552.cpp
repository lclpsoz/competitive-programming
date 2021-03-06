#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int MAXN = 505;

int link[MAXN], size[MAXN];

int find (int x)
{
	while (x != link[x])
		x = link[x];
	return x;
}

int unite (int x, int y)
{
	x = find (x);
	y = find (y);
	if (size[x] > size[y])
		swap (x, y);
	size[y] += size[x];
	link[x] = y;
}

bool same (int x, int y)
{
	return find(x) == find(y);
}

int pot2 (int x)
{
	return x*x;
}

int main ()
{
	int t, n;
	int x, y;
	vector<piii> vert;
	set<piii> st;
	double ans;

	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		int n1 = n;
		vert.clear ();
		while (n--) {
			scanf ("%d %d", &x, &y);

			for (piii aux : vert)
				st.insert ({(pot2 (aux.second.first-x)+pot2 (aux.second.second-y)), {aux.first, n}});

			vert.push_back ({n, {x, y}});
		}

		for (int i = 0; i < n1; i++) {
			link[i] = i;
			size[i] = 1;
		}

		ans = 0.0;
		while (!st.empty ()) {
			int p = st.begin()->first;
			x = st.begin()->second.first;
			y = st.begin()->second.second;
			st.erase (st.begin());
			if (!same (x, y)) {
				unite (x, y);
				ans += sqrt (p);
			}
		}

		printf ("%.2lf\n", ans/100);

	}

	return 0;
}