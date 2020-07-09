#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3+10;
typedef pair<int, int> pii;

int n, g, a, b;
char arr[30];
string str;
map<string, int> mp;
string mp_arr[MAXN];
vector<int> adj[MAXN];
bool vert[MAXN];

int main ()
{
	scanf ("%d %d", &n, &g);
	str = "Rerisson";
	mp[str] = 1;
	int i = 2;
	while (n--) {
		scanf ("%s", arr);
		str = arr;
		if (!mp[str]) {
			mp_arr[i] = str;
			mp[str] = i++;
		}
		a = mp[str];
		scanf ("%s", arr);
		str = arr;
		if (!mp[str]) {
			mp_arr[i] = str;
			mp[str] = i++;
		}
		b = mp[str];
		adj[a].push_back (b);
		adj[b].push_back (a);
	}

	queue<pii> q;
	q.push ({0, 1}); // degree, vertice
	set<string> names;
	while (!q.empty() && q.front ().first <= g) {
		int w = q.front().first;
		int v = q.front().second;
		q.pop ();
		if (vert[v]) continue;
		if (v > 1)
			names.insert (mp_arr[v]);
		vert[v] = true;

		for (int x : adj[v])
			q.push ({w+1, x});
	}
	printf ("%ld\n", names.size());
	for (string s : names)
		cout << s << '\n';

	return 0;
}
