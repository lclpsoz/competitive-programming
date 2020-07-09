#include <bits/stdc++.h>
using namespace std;

int n, m, n1, m1;
char mat[55][55];

int main ()
{
	while (scanf ("%d %d ", &n, &m), n && m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				mat[i][j] = getchar ();
			getchar (); //\n
		}
		scanf ("%d %d", &n1, &m1);
		n1 /= n;
		m1 /= m;
		int ii = n1; int jj = m1;
		for (int i = 0; i < n; i++) {
			while (ii--) {
				for (int j = 0; j < m; j++) {
					while (jj--)
						putchar (mat[i][j]);
					jj = m1;
				}
				putchar ('\n');
			}
			ii = n1;
		}
		putchar ('\n');
	}

	return 0;
}
