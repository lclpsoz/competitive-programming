#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;

queue <int> q;
set <int> arr [MAXN];
bool verif[MAXN];
bool now[MAXN];

int main ()
{
	int t;
	int doc, dep;
	int a, b;
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf ("%d %d", &doc, &dep);
		for (int j = 0; j < dep; j++) {
			scanf ("%d %d", &a, &b);
			doc = max (doc, max (a, b));
			arr[a].insert (b);
		}

		bool tem_loop = false;
		for (int j = 1; j <= doc && !tem_loop; j++) {
			if (!verif[j] && !arr[j].empty ()) {
				for (int j = 0; j <= doc+1; j++)
					now[j] = false;

				q.push (j);
				verif[j] = true;
				while (!tem_loop && !q.empty ()) {
					int aux = q.front ();
					q.pop ();
					now[aux] = true;
					verif[aux] = true;
					for (int x : arr[aux]) {
						if (now[x]) {
							tem_loop = true;
							break;
						}
						if (!verif[x])
							q.push (x);
					}
				}

				while (!q.empty ())
					q.pop ();
			}
		}

		tem_loop ? printf ("SIM\n") : printf ("NAO\n");

		for (int j = 0; j <= doc+1; j++) {
			verif[j] = false;
			arr[j].clear ();
		}

	}

	return 0;
}
