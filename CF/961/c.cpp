#include <bits/stdc++.h>
using namespace std;

int n;
bool mat[205][205];
bool inp[5][105][105];
bool choosen[4];
int ans;

int func (int x, int y) {
	int mini = 1e9;
	int aux = 0;
	int pos;
	//printf ("x: %d y: %d\n", x, y);
	for (int i = 0; i < 4; i++) {
		if (!choosen[i]) {
			aux = 0;
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					//printf ("%d", inp[i][j][k]);
					if (mat[x+j][y+k] != inp[i][j][k])
						aux++;
				}
				//putchar ('\n');
			}
				//printf ("%d\n", aux);

			if (aux < mini) {
				mini = aux;
				pos = i;
			}
		}
	}
	choosen[pos] = true;
	//printf ("%d -> %d\n", pos, mini);
	return mini;
}

int main ()
{
	for (int i = 0; i < 205; i++)
		for (int j = 0; j < 205; j++)
			if (i%2)
				mat[i][j] = !(j%2);
			else
				mat[i][j] = (j%2);
	scanf ("%d", &n);
	/*for (int i = 0; i < n+n; i++) {
		for (int j = 0; j < n+n; j++)
			printf ("%d", mat[i][j]);
		putchar ('\n');
	}
	putchar ('\n');*/
	int x;
	for (int k = 0; k < 4; k++)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf ("%1d", &x);
				// printf ("%d", x);
				if (x) inp[k][i][j] = true;
			}
			//putchar ('\n');
		}
	//putchar ('\n');

	ans += func(0, 0);
	ans += func(0, n);
	ans += func(n, 0);
	ans += func(n, n);
	printf ("%d\n", ans);

	return 0;
}
