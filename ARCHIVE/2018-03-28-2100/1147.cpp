#include <bits/stdc++.h>
using namespace std;

int i, j;
int mat[10][10], ans, row, col, x, y;

int main ()
{
	while (scanf("%d", &row), row) {
		col = (getchar()) - 'a' + 1;
		getchar(); //\n
		for (i = 0; i < 8; i++) {
			y = (getchar()) - '0';
			x = getchar() - 'a' + 1;
			mat[y][x] = 1;
			getchar(); //\n
		}
	}
	return 0;
}
