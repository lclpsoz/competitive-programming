#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int st = 50, n = 2*st - 2;
int nn;
map<int, int> mp;
int matBrute[105][105];

int adj[][2] = {	{2, 1},
					{2, -1},
					{-2, 1},
					{-2, -1},
					{1, 2},
					{1, -2},
					{-1, 2},
					{-1, -2}};

int getDist (int x, int y) {
	int diag = x + y;
	int mid = diag/3 + diag%3;
	int qntE = diag/3 - diag%3;
	int mini = min (x, y);
	//  if (x == 3 and y == 18)
	//  	printf ("diag = %d, mid = %d, qntE = %d\n", diag, mid, qntE);
	if (mini >= qntE)
		return mid;
	else
		return mid + 2*((qntE-mini-1)/4 + 1);
}

void prt () {
	// printf ("  | ");
	// for (int j = 0; j < st - 1; j++)
	// 	printf ("%2d ", j);
	// 	putchar ('\n');
	// for (int j = 0; j < (3*(st)); j++)
	// 	putchar ('-');
	// 	putchar ('\n');
	// for (int i = st; i <= n; i++) {
	// 	printf ("%2d| ", i-st);
	// 	for (int j = st; j <= n; j++)
	// 		printf ("%2d%c", matBrute[i][j], " \n"[j==n]);
	// }

	// printf ("  | ");
	// for (int j = 0; j < 90-51+1; j++)
	// 	printf ("%2d ", j);
	// 	putchar ('\n');
	// for (int j = 0; j < 125; j++)
	// 	putchar ('-');
	// 	putchar ('\n');
	// for (int d = 0; d <= 39; d++) {
	// 	printf ("%2d| ", d);
	// 	int j = 0+51, i = d+51;

	// 	int diag = i-51 + j-51;
	// 	int mid = diag/3 + diag%3;
	// 	int qntE = diag/3 - diag%3;
	// 	int mini = min (i-51, j);
	// 	// printf ("mid = %d, qntE = %d\n", mid, qntE);
	// 	int cmp = -1;
	// 	if (mini >= qntE)
	// 		cmp = mid;
	// 	else {
	// 		cmp = mid + 2*(qntE-mini+3)/4;
	// 	}
	// 	while (i >= 51)
	// 		if (cmp != matBrute[i--][j++]) {
	// 			printf ("fuck! %d %d\n", i+1-51, j-1-51);
	// 			printf ("%d %d\n", cmp, matBrute[i+1][j-1]);	
	// 			diag = (i-51) + (j-51);
	// 	mid = diag/3 + diag%3;
	// 	 qntE = diag/3 - diag%3;
	// 	 mini = min (i-51, j-51);
	// 	// printf ("mid = %d, qntE = %d\n", mid, qntE);
	// 	 cmp = -1;
	// 	if (mini >= qntE)
	// 		cmp = mid;
	// 	else {
	// 		cmp = mid + 2*(qntE-mini+3)/4;
	// 	}
	// 		}
	// 		// printf ("%2d ", matBrute[i--][j++]);
	// 	putchar ('\n');
	// }


	// int x, y;
	// while (scanf ("%d %d", &x, &y) != EOF) {
	// 	int diag = x + y;
	// 	int mid = diag/3 + diag%3;
	// 	int qntE = diag/3 - diag%3;
	// 	int mini = min (x, y);
	// 	printf ("mid = %d, qntE = %d\n", mid, qntE);
	// 	if (mini >= qntE)
	// 		printf ("%d\n", mid);
	// 	else {
	// 		printf ("%d\n", mid + 2*(qntE-mini+3)/4);
	// 	}
	// }
	/*
	for (int x = 0; x < 50; x++)
	for (int y = 0; y < 50; y++)
	if (min (x, y) < 10){
		// printf ("%d\n", matBrute[x+51][y+51]);
		int z = -1;
	}
	else {
		int diag = x + y;
		int mid = diag/3 + diag%3;
		int qntE = diag/3 - diag%3;
		int mini = min (x, y);
		// printf ("mid = %d, qntE = %d\n", mid, qntE);
		// printf ("-- %d %d\n", x, y);
		if (mini >= qntE) {
			// printf ("%d\n", mid);
			if (min (x, y) < 40)
				if (mid != matBrute[x+51][y+51]) printf ("HELL in %d %d!!\n", x, y);
		}
		else {
			// printf ("%d\n", mid + 2*(qntE-mini+3)/4);
			if (min (x, y) < 40)
				if (matBrute[x+51][y+51] != mid + 2*((qntE-mini+3)/4)) printf ("FUCKED in %d %d!! %d vs %d\n", x, y, matBrute[x][y], mid + 2*(qntE-mini+3)/4);
		}
	}
	*/
}

int main () {
	memset (matBrute, -1, sizeof matBrute);
	// for (int i = 40; i <= 70; i++)
	// 	for (int j = 40; j <= 70; j++)
	// 		printf ("%2d%c", matBrute[i][j], " \n"[j==70]);

	queue<pair<pii, int>> q;
	q.push({{st, st}, 0});
	while (!q.empty()) {
		int x = q.front().x.x, y = q.front().x.y;
		int d = q.front().y;
		q.pop();
		if (x >= n or x < 2 or y < 2 or y >= n or matBrute[x][y] != -1) continue;
		matBrute[x][y] = d;
		for (int i = 0; i < 8; i++) {
			int dx = adj[i][0], dy = adj[i][1];    
			q.push ({{x+dx, y+dy}, d+1});
		}
	}

	scanf ("%d", &nn);
	int a, b;
	scanf ("%d %d", &a, &b);
	int x, y;
	// bool close = false;
	scanf ("%d %d", &x, &y);
	// if (abs (x) + 6 >= nn or abs (y) + 6 >= nn)
	// 	close = true;
	x -= a;
	y -= b;
	x = abs (x);
	y = abs (y);
	if (min (x, y) < 10)
		printf ("%d\n", matBrute[x+st][y+st]);
	else
		printf ("%d\n", getDist (x, y));

	// for (int x = 0; x < n-st; x++)
	// 	for (int y = 0; y < n-st; y++)
	// 		if (min(x, y) > 2 and getDist (x, y) != matBrute[x+st][y+st]) {
	// 			printf ("(%d, %d) -> %d vs %d\n", x, y, getDist (x, y), matBrute[x+st][y+st]);
	// 		}		
	// prt();

	return 0;
}
