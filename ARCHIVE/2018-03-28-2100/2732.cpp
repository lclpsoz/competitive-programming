#include <bits/stdc++.h>
using namespace std;

const int dir[4][2] = {	{-1, 0},
						{0,-1},
						{1, 0},
						{0, 1}	};

int h, l;
bool city[405][405];

int dfs (int i, int j)
{
	city[i][j] = false;
	int ret = 1;
	for (int k = 0; k < 4; k++) {
		if (city[dir[k][0]+i][dir[k][1]+j])
			ret += dfs (dir[k][0]+i, dir[k][1]+j);
	}

	return ret;
}

int main ()
{
	scanf ("%d %d", &h, &l);
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= l; j++) {
			getchar ();
			city[i][j] = (getchar () == 'C');
		}

	int ans = 0;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= l; j++)
			if (city[i][j])
				ans = max (dfs (i, j), ans);

	printf ("%d\n", ans);

	return 0;
}
