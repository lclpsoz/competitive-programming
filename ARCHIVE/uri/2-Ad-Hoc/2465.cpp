#include <bits/stdc++.h>
using namespace std;

int i, j;
int size, x, y;
int mat[105][105];
bool flag[105][105];

int move (int a, int b){

	int moves = 1;
	int now = mat[a][b];

	flag[a][b] = true; //Flag is up
	if (!flag[a][b+1] && now <= mat[a][b+1]){

		moves += move(a, b+1);

	}
	if (!flag[a-1][b] && now <= mat[a-1][b]){

		moves += move(a-1, b);

	}
	if (!flag[a][b-1] && now <= mat[a][b-1]){

		moves += move(a, b-1);

	}
	if (!flag[a+1][b] && now <= mat[a+1][b]){

		moves += move(a+1, b);

	}

	return moves;

}

int main (){

	scanf("%d", &size);
	scanf("%d %d", &x, &y);

	for (i = 1; i <= size; i++)
		for (j = 1; j <= size; j++)
			scanf("%d", &mat[i][j]);

	printf("%d\n", move(x, y));

	return 0;
}
