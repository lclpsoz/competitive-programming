#include <bits/stdc++.h>
using namespace std;

int q, x;
deque <int> bees;
char str[100];

int main ()
{
	scanf ("%d", &q);
	bool order = true;
	for (int i = 0; i < q; i++) {
		scanf ("%s", str);
		if (!strcmp (str, "toFront")) {
			scanf ("%d", &x);
			if (order)
				bees.push_front (x);
			else
				bees.push_back (x);
		}
		else if (!(strcmp (str, "push_back"))) {
			scanf ("%d", &x);
			if (order)
				bees.push_back (x);
			else
				bees.push_front (x);
		}
		else if (!strcmp (str, "reverse"))
			order = !order;
		else if (bees.empty ())
			printf ("No job for Ada?\n");
		else if (!strcmp (str, "front")) {
			if (order) {
				printf ("%d\n", bees.front ());
				bees.pop_front ();
			}
			else {
				printf ("%d\n", bees.back ());
				bees.pop_back ();
			}
		}
		else if (!strcmp (str, "back")) {
			if (order) {
				printf ("%d\n", bees.back ());
				bees.pop_back ();
			}
			else {
				printf ("%d\n", bees.front ());
				bees.pop_front ();
			}
		}
	}
	return 0;
}
