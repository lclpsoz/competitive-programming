#include <bits/stdc++.h>
using namespace std;

int n;
char arr1[150], arr2[150];
string str;
map<string, int> wiki;
set<int> adj[2050];
set<string> conjunto;

int main ()
{
	scanf ("%d", &n);
	int pos = 1;
	int a, b;
	for (int i = 0; i < n; i++) {
		scanf ("%s %s", arr1, arr2);
		str = arr1;
		if (wiki[str] == 0)
			wiki[str] = pos;
		a = wiki[str];
		conjunto.insert (str);

		str = arr2;
		if (wiki[str] == 0)
			wiki[str] = pos;
		b = wiki[str];

		adj[a].insert (b);
		conjunto.insert (str);
	}

	for (string s : conjunto)
		cout << s << '\n';

	return 0;
}
