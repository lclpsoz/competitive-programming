#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 1e3+10;

int n;
char c;
vector<int> ans;
int size[MAXN], link[MAXN];
stack<pii> desc;

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
	// printf ("enter:%d %d\n", x, y);
	x = find (x);
	y = find (y);
	if (x != y) {
		// printf ("find: %d %d\n", x, y);
		// printf ("%d + %d = ", size[x], size[y]);
		if (size[x] > size[y])
			swap (x, y);
		size[y] += size[x];
		link[x] = y;
	}
	// printf ("%d\n", size[y]);
}

bool func ()
{
	// Reset UNION-FIND
	for (int i = 0; i < n; i++) {
		size[i] = 1;
		link[i] = i;
	}

	for (int i = 0; i < n; i++) {
		getchar (); // '\n'
		for (int j = 0; j < n; j++) {
			if (c = getchar(), i < j) {
				// printf ("%d %d → %d %d\n", i, j, find(i), find(j));
				if (c == 'S')
					unite (i, j);
				else
					desc.push ({i, j});
			}
		}
	}
	while (!desc.empty ()) {
		if (same (desc.top().first, desc.top().second))
			return false;
		desc.pop();
	}
	for (int i = 0; i < n; i++)
		if (link[i] == i)
			ans.push_back (size[i]);
	sort (ans.begin(), ans.end(), greater<int>());
	return true;
}

int main ()
{
	scanf ("%d", &n);
	if (func ()) {
		printf ("%ld\n", ans.size());
		for (int i = 0; i < ans.size(); i++) {
			printf ("%d", ans[i]);
			if (i < ans.size()-1)
				putchar (' ');
		}
	} else {
		putchar ('-');
		putchar ('1');
	}
	putchar ('\n');

	return 0;
}
