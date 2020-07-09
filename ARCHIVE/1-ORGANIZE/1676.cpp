#include <bits/stdc++.h>
using namespace std;

list<int> part;
vector<int> ans;

int main ()
{
	for (int i = 2; i < 1e5; i++)
		part.push_back (i);
	int est = 1;
	auto st = part.begin ();
	auto act = st;
	for (int i = 2; st != part.end () && est && i < 5e4; i++, st++) {
		est = 0;
		act = st;
		//printf (":%d\n", *st);
		act++;
		while (act != part.end ()) {
			for (int j = 1; act != part.end () && j < *st; j++) {
				//printf ("::%d\n", *act);
				act++;
			}
			if (act != part.end ()) {
				//printf (":::%d\n", *act);
				est++;
				auto aux = act;
				aux++;
				//printf (":::%d\n", *act);
				part.erase (act);
				act = aux;
			}
		}
	}
	st = part.begin ();
	for (int i = 0; i <= 3e3; i++) {
		ans.push_back (*st);
		st++;
	}
	while (scanf ("%d", &est), est)
		printf ("%d\n", ans[est-1]);

	return 0;
}
