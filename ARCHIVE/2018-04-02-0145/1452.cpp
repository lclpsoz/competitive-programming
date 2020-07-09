#include <bits/stdc++.h>
using namespace std;

int s, c, n, ans;
string str;
char arr[30];
set<string> servers[210];
bool check[210];

int main ()
{
	while (scanf ("%d %d", &s, &c), s || c) {
		ans = 0;
		for (int i = 0; i < s; i++)
			servers[i].clear();

		for (int i = 0; i < s; i++) {
			scanf ("%d", &n);
			while (n--) {
				scanf ("%s", arr);
				str = arr;
				servers[i].insert (str);
			}
		}

		while (c--) {
			scanf ("%d", &n);
			while (n--) {
				scanf ("%s", arr);
				str = arr;
				for (int i = 0; i < s; i++)
					if (servers[i].find (str) != servers[i].end())
						check[i] = true;
			}
			for (int i = 0; i < s; i++) {
				ans += check[i];
				check[i] = false;
			}
		}
		printf ("%d\n", ans);
	}

	return 0;
}
