#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int n;
string comp[35];
char arr[20];
vector<int> adj[35];
vector<string> vec;
bool check[35];

int getIdx (string str) {
	return lower_bound (comp, comp+n, str)-comp;
}

int main ()
{
	int ttt = 1;
	while (scanf ("%d", &n), n) {
		for (int i = 0; i < 31; i++) {
			adj[i].clear();
			check[i] = false;
		}
		for (int i = 0; i < n; i++) {
			scanf ("%s", arr);
			printf ("%s\n", arr);
			comp[i] = arr;
		}
		sort (comp, comp+n);

		/*for (int i = 0; i < n; i++) {
			cout << comp[i] << " " << getIdx (comp[i]) << '\n';
		}*/

		int v, u;
		int m;
		for (int i = 0; i < n; i++) {
			scanf ("%s", arr);
			v = getIdx (arr);
			scanf ("%d", &m);
			while (m--) {
				scanf ("%s", arr);
				u = getIdx (arr);
				adj[v].pb (u);
			}
		}

		vec.clear();
		bool t;
		for (int k = 0; k < n; k++)
			for (int i = 0; vec.size() < n && i < n; i++) {
				if (!check[i]) {
					t = true;
					for (int a : adj[i])
						if (!check[a]) {
							t = false;
							break;
						}
					if (t) {
						vec.pb (comp[i]);
						check[i] = true;
					}
				}
			}

		printf ("Teste %d\n", ttt++);
		if (vec.size() == n) {
			for (string s : vec)
				cout << s << ' ';
		}
		else
			printf ("impossivel");
		putchar ('\n');
		putchar ('\n');
	}
	return 0;
}
