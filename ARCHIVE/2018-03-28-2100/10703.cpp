#include <cstdio>
#include <algorithm>

int i, j, k;
bool mat[505][505];
int h, w, n;
int x1, y1, x2, y2;
int empty;

int main ()
{
	while (scanf ("%d %d %d", &w, &h, &n), w || h || n) {
		for (i = 0; i < n; i++) {
			scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
			if (x1 > x2)
				std::swap (x1, x2);
			if (y1 > y2)
				std::swap (y1, y2);
			for (j = x1; j <= x2; j++)
				for (k = y1; k <= y2; k++)
					mat[j][k] = true;
		}
		empty = 0;
		for (i = 1; i <= w; i++)
			for (j = 1; j <= h; j++)
				if (!mat[i][j])
					empty++;
				else
					mat[i][j] = false;
		if (empty == 0)
			printf ("There is no empty spots.\n");
		else if (empty == 1)
			printf ("There is one empty spot.\n");
		else
			printf ("There are %d empty spots.\n", empty);
	}

	return 0;
}
