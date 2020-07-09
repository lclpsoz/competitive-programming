#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+100;

struct reg {
	int x, y;
};

int a, b, n, aux, size, dir;
int mat[MAXN][MAXN];
struct reg p;

int main ()
{
	while (scanf ("%d %d", &a, &b) != EOF) {
		if (3*b > a)
			printf ("Raios! Raios Duplos! Raios Triplos!\n");
		else {
			n = sqrt (a);
			aux = a;
			p.x = p.y = 0;
			bool road = true;
			mat[0][0] = aux--;
			n--;
			dir = 0;
			while (road) {
				if (dir == 0 && p.y < n && !mat[p.x][p.y+1]) {
					p.y++;
					dir = 0;
					if (p.y == n || mat[p.x][p.y+1])
						dir = 1;
				}
				else if (dir == 1 && p.x < n && !mat[p.x+1][p.y]) {
					p.x++;
					dir = 1;
					if (p.x == n || mat[p.x+1][p.y])
						dir = 2;
				}
				else if (dir == 2 && p.y > 0 && !mat[p.x][p.y-1]) {
					p.y--;
					dir = 2;
					if (p.y == 0 || mat[p.x][p.y-1])
						dir = 3;
				}
				else if (dir == 3 && p.x > 0 && !mat[p.x-1][p.y]) {
					p.x--;
					dir = 3;
					if (p.x == 0 || mat[p.x-1][p.y])
						dir = 0;
				}
				else
					road = false;
				mat[p.x][p.y] = aux--;
			}
			n++;
			if (n&1)
				mat[(n/2)][n/2] = 1;
			else
				mat[(n/2)][n/2-1] = 1;
			size = (int)(log10 (a)+1);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (mat[i][j] == 3*b)
						printf ("%*c", size, '!');
					else if (mat[i][j] == 2*b)
						printf ("%*c", size, '*');
					else
						printf ("%*d", size, mat[i][j]);
					mat[i][j] = 0;
					if (i != n-1 || j != n-1)
						putchar (' ');
				}
				putchar ('\n');
			}
		}
	}
	return 0;
}
