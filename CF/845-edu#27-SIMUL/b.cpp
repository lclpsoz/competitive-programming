#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

char arr[10];
int aux[10];
int main ()
{
	scanf ("%s", arr);
	int l, r;
	l = r = 0;
	for (int i = 0; i < 6; i++) {
		aux[i] = arr[i]-'0';
		if (i < 3)
			l += aux[i];
		else
			r += aux[i];
	}
	bool prt = false;
	if (l == r)
		printf ("0\n");
	else {
		sort (aux, aux+3);
		sort (aux+3, aux+6);
		// Only ONE
		if (l < r) {
			int x = r-l;
			if (aux[0]+x <= 9 || aux[5]-x >= 0) {
				printf ("1\n");
				prt = true;
			}
		}
		if (!prt && r < l) {
			int x = l-r;
			if ((aux[3]+x) <= 9 || aux[2]-x >= 0) {
				printf ("1\n");
				prt = true;
			}
		}
		// TWO
		if (!prt && l < r) {
			int x = r-l;
			if (x <= ((aux[5])+(9-aux[0]))) {
				printf ("2\n");
				prt = true;
			}
			else if ((18-aux[0]-aux[1]) >= x) {
				printf ("2\n");
				prt = true;
			}
			else if ((aux[4]+aux[5]) >= x) {
				printf ("2\n");
				prt = true;
			}
		}
		if (!prt && l > r) {
			int x = l-r;
			// printf ("%d\n", x);
			if (x <= ((aux[2])+(9-aux[3]))) {
				printf ("2\n");
				prt = true;
			}
			else if ((18-aux[3]-aux[4]) >= x) {
				printf ("2\n");
				prt = true;
			}
			else if ((aux[1]+aux[2]) >= x) {
				printf ("2\n");
				prt = true;
			}

		}
		if (!prt)
			printf ("3\n");
	}

	return 0;
}
