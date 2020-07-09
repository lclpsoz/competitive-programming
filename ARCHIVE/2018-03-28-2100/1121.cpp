#include <bits/stdc++.h>
using namespace std;

int n, m, s;
char c;
char mat[105][105];
pair <int, int> coord;
int dir;
int ans;

int direct (char c) {
	switch (c) {
		case 'N': return 0;
		case 'L': return 1;
		case 'S': return 2;
		case 'O': return 3;
	}
}

bool can_move (int a, int b)
{
	if (a < 0 || a >= n)
		return false;
	if (b < 0 || b >= m)
		return false;
	if (mat[a][b] == '#')
		return false;
	return true;
}

void cell (int a, int b) {
	if (mat[a][b] == '*')
		ans++;
	mat[a][b] = '.';
	coord.first = a;
	coord.second = b;
}

void move () {
	int a = coord.first;
	int b = coord.second;
	switch (dir) {
		case 0:
			if (can_move (a-1, b))
				cell (a-1, b);
			break;
		case 1:
			if (can_move (a, b+1))
				cell (a, b+1);
			break;
		case 2:
			if (can_move (a+1, b))
				cell (a+1, b);
			break;
		case 3:
			if (can_move (a, b-1))
				cell (a, b-1);
			break;

	}
}

int main ()
{
	while (scanf ("%d %d %d", &n, &m, &s), n || m || s) {
		ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf (" %c", &mat[i][j]);
				if (mat[i][j] >= 'A' && mat[i][j] <= 'Z') {
					coord.first = i;
					coord.second = j;
					dir = direct (mat[i][j]);
					mat[i][j] = '.';
				}
			}
		for (int i = 0; i < s; i++) {
			scanf (" %c", &c);
			switch (c) {
				case 'D': dir = (dir+1)%4;
						  break;
				case 'E': if (dir == 0)
							  dir = 3;
						  else
							  dir--;
						  break;
				case 'F': move ();
						  break;
			}

		}
		printf ("%d\n", ans);
	}
	return 0;
}
