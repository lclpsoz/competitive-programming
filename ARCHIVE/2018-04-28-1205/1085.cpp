#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<char, int>> pci;
const int MAXN = 4e3+10;

int n;
char arr1[60], arr2[60], arr3[60];
string str;
map<string, int> mp;
vector<pci> adj[MAXN];
priority_queue<pci, vector<pci>, greater<pci>> q;

int main ()
{
	int verif[MAXN];
	while (scanf ("%d", &n), n) {
		scanf ("%s %s", arr1, arr2);
		str = arr1;
		mp[str] = 1;
		str = arr2;
		int en = 2*n+2;
		for (int i = 0; i <= en; i++) {
			adj[i].clear();
			verif[i] = 0;
		}
		mp[str] = en;
		int i = 2;
		int x1, x2;
		while (n--) {
			scanf ("%s %s %s", arr1, arr2, arr3);
			str = arr1;
			if (!mp[str])
				mp[str] = i++;
			x1 = mp[str];
			str = arr2;
			if (!mp[str])
				mp[str] = i++;
			x2 = mp[str];
			// printf ("%s %s %d %d\n", arr1, arr2, x1, x2);
			adj[x1].push_back ({strlen(arr3),{arr3[0], x2}});
			adj[x2].push_back ({strlen(arr3),{arr3[0], x1}});
		}

		q.push ({0, {'z'+1, 1}});
		while (!q.empty () && q.top().second.second != en) {
			x1 = q.top().second.second;
			int w = q.top().first;
			char c = q.top().second.first;
			// printf ("%d %c %d\n", x1, c, w);
			q.pop ();
			if (verif[x1] & 1<<(c-'a')) continue;
			verif[x1] |= 1<<(c-'a');
			for (pci x : adj[x1])
				if (x.second.first != c) {
					// printf ("\t%d %c [%d]\n", x.second.second, x.second.first, x.first);
					q.push ({w+x.first, {x.second}});
				}
		}

		// printf ("%d %c [%d]\n", q.top().second.second, q.top().second.first, q.top().first);
		q.empty () ? printf ("impossivel\n") : printf ("%d\n", q.top().first);
		mp.clear ();
		while (!q.empty ())
			q.pop();

	}

	return 0;
}
