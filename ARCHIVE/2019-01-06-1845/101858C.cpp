#include "stdio.h"
#include "stdlib.h"

const int IDROW = 0;
const int IDCOL = 6;
const int IDGRID = 12;
const int IDREG = 18;

inline int getGrid (int x, int y) {
	return (x/2) + ((y >= 3) ? 3 : 0);
}

int n, gdMap[7][7];
int regVals[40], regMap[7][7], mp[7][7], qnt[40];
bool used[60][7];

void ans () {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (j) putchar (' ');
			printf ("%d", mp[i][j]);
		}
		putchar ('\n');
	}
		
	exit (0);
}

void solve (int x, int y) {
	if (y == 6)
		y = 0, ++x;
// 	printf ("%d %d\n", x, y);
	if (x == 6)
		ans ();
	int &gd = gdMap[x][y];
	int &rg = regMap[x][y];
	for (int i = 1; i <= 6; i++)
		if (!used[x][i] and !used[IDCOL+y][i] and
			!used[IDGRID+gd][i] and !used[IDREG+rg][i]) {
			qnt[rg]--;
			regVals[rg] -= i;
			if (!qnt[rg] and regVals[rg]) {
				qnt[rg]++;
				regVals[rg] += i;
// 				printf ("INVALID\n");
				continue;
			}
			
// 			printf ("(%d %d) -> %d is ", x, y, i); 
			used[x][i] = used[IDCOL+y][i] =
			used[IDGRID+gd][i] = used[IDREG+rg][i] = true;
			mp[x][y] = i;
// 			printf ("VALID\n");
			solve (x, y+1);
		
			// Cancel everything
			qnt[rg]++;
			regVals[rg] += i;
			used[x][i] = used[IDCOL+y][i] =
			used[IDGRID+gd][i] = used[IDREG+rg][i] = false;
		}
	
	if (x == 5 and y == 5)
		ans ();
}

int main () {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			gdMap[i][j] = getGrid (i, j);
	
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &regVals[i]);
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++) {
			int x;
			scanf ("%d", &x);
			--x;
			qnt[x]++;
			regMap[i][j] = x;
		}
		
	solve (0, 0);	

	return 0;
}
