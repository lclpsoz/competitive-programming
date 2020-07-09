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

	queue<int> now, next;
	int lvl = 0;
	now.push (1);
	set<string> names;
	while (!now.empty() && lvl <= g) {
		int v = now.front();
		now.pop ();
		if (v > 1)
			names.insert (mp_arr[v]);
		vert[v] = true;

		for (int x : adj[v])
			next.push (x);
		while (!now.empty () && vert[now.front()])
			now.pop();
		if (now.empty()) {
			now = next;
			while (!next.empty())
				next.pop();
			lvl++;
		}
	}
	printf ("%ld\n", names.size());
	for (string s : names)
		cout << s << '\n';

	return 0;
}
