#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> piii;

const int MAXN = 2e5+10;

int n, m;
int a, b, p;
int arr[MAXN];
int size[MAXN];
priority_queue <piii, vector<piii>, greater<piii>> roads;

int find (int x)
{
	while (arr[x] != x) x = arr[x];
	return x;
}

void uni (int x, int y)
{
	x = find (x);
	y = find (y);
	if (size[x] > size[y])
		swap (x, y);
	size[y] += size[x];
	arr[x] = y;
}

bool check (int x, int y){return find (x) == find (y);}

int main ()
{
	while (scanf ("%d %d", &m, &n), n || m) {
		while (n--) {
			scanf ("%d %d %d", &a, &b, &p);
			roads.push ({p, {a, b}});
		}
		for (int i = 0; i < m; i++) {
			arr[i] = i;
			size[i] = 1;
		}
		/*for (int i = 0; i < m;i++)
			printf ("%d: %d\n", i, arr[i]);*/
		int ans = 0, total = 0;
		while (!roads.empty ()) {
			piii aux = roads.top ();
			a = aux.second.first;
			b = aux.second.second;
			roads.pop();
			if (!check (a, b)) {
				uni (a, b);
				ans += aux.first;
			}
			total += aux.first;
			// printf ("%d %d %d\n", aux.first, aux.second.first, aux.second.second);
		}
		// for (int i = 0; i < m;i++)
			// printf ("%d: %d\n", i, arr[i]);
		printf ("%d\n", total-ans);
	}
	return 0;
}
