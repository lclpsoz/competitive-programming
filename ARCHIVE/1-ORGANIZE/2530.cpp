#include <bits/stdc++.h>
using namespace std;

int n, m, x;
queue <int> juan;

int main ()
{
	bool ans;
	while (scanf ("%d %d", &n, &m) != EOF) {
		ans = true; // Cheating
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			juan.push (x);
		}
		for (int i = 0; i < m; i++) {
			scanf ("%d", &x);
			while (ans && !juan.empty () && juan.front () != x) {
				//printf ("%d x:%d\n", juan.front (), x);
				juan.pop ();
			}
			if (juan.empty ()) {
				//printf ("%d\n", x);
				ans = false; //Not cheating
			}
			if (!juan.empty ()) {
				//printf ("%d %d\n", juan.front (), x);
				juan.pop ();
			}
		}
		while (!juan.empty())
			juan.pop();
		ans ? puts ("sim") : puts ("nao");
	}
	return 0;
}
