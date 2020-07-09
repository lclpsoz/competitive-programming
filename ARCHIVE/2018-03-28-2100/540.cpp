#include <bits/stdc++.h>
using namespace std;

const int MAXQ = 2e5+100, MAXE = 1e6+100, MAXT = 1e3+100;

char arr[20];
pair <int, queue <int> > que[MAXQ];
int elem[MAXE], teams[MAXT];
int st, en;

void que_push (int x)
{
	if (teams[elem[x]])
		que[teams[elem[x]]-1].second.push (x);
	else {
		teams[elem[x]] = en+1;
		que[en].first = elem[x];
		que[en++].second.push (x);
	}
}

void que_pop ()
{
	//printf ("%d %d\n", st, en);
	printf ("%d\n", que[st].second.front ());
	que[st].second.pop ();
	if (que[st].second.empty()) {
		teams[que[st].first] = 0;
		que[st++].first = 0;
	}
}

void g_clear ()
{
	for (int i = 0; i < MAXE; i++)
		elem[i] = 0;
	for (int i = 0; i < MAXT; i++)
		teams[i] = 0;
	for (int i = 0; i < MAXQ; i++) {
		que[i].first = 0;
		while (!que[i].second.empty ())
			que[i].second.pop ();
	}
}

int main ()
{
	int t, n, x, amnt = 1;
	while (scanf ("%d", &t), t) {
		printf ("Scenario #%d\n", amnt++);
		st = 0;
		en = 0;
		// Team 1..t
		for (int i = 1; i <= t; i++) {
			scanf ("%d", &n);
			for (int j = 0; j < n; j++) {
				scanf ("%d", &x);
				elem[x] = i;
			}
		}
		while (scanf ("%s", arr), arr[0] != 'S') {
			if (arr[0] == 'E') {
				scanf ("%d", &x);
				que_push (x);
			}
			else
				que_pop ();
		}
		g_clear ();
		putchar ('\n');
	}

	return 0;
}
