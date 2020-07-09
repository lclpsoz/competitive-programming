#include <bits/stdc++.h>
using namespace std;

int i;
int n, stu, x, cont;
vector < pair <int, pair <int, int> > > scr;

bool ord (const pair<int, pair <int, int> > &a, const pair<int, pair <int, int> > &b) {
	if (a.second.second > b.second.second)
		return true;
	else if (a.second.second < b.second.second)
		return false;
	else if (a.first < b.first)
		return true;
	else
		return false;
}

int main ()
{
	while (scanf ("%d", &n), n) {
		printf ("Turma %d\n", ++cont);
		for (i = 0; i < n; i++) {
			scanf ("%d %d", &stu, &x);
			scr.insert(scr.end(), make_pair(i, make_pair (stu, x)));
		}
		sort (scr.begin(), scr.end(), ord);
		for (i = 0; i < n; i++) {
			printf ("%d %d\n", scr[i].second.first, scr[i].second.second);
		}
		i = 0;
		while (scr[i].second.second == scr[0].second.second) {
			printf ("%d ", scr[i++].second.first);
		}
		scr.clear ();
		printf ("\n\n");
	}
	return 0;
}
