#include <bits/stdc++.h>
using namespace std;

int i, j, k;
int qnt, mat[4][4], ans[5]; //ANS: SOME, DOWN, LEFT, RIGHT, UP

int main ()
{
	scanf ("%d", &qnt);
	for (i = 0; i < qnt; i++) {
		for (j = 0; j < 5; j++)
			ans[j] = 0;

		for (j = 0; j < 4; j++)
			for (k = 0; k < 4; k++)
				scanf("%d", &mat[j][k]);

		for (j = 0; j < 4; j++)
			for (k = 0; k < 4; k++) {
				if (mat[j][k]) {
					if (!ans[3] && k < 3 && (mat[j][k+1] == 0 || mat[j][k+1] == mat[j][k])) {
						ans[0]++;
						ans[3] = 1; //RIGHT
					}
					if (!ans[2] && k > 0 && (mat[j][k-1] == 0 || mat[j][k-1] == mat[j][k])) {
						ans[0]++;
						ans[2] = 1; //LEFT
					}
					if (!ans[1] && j < 3 && (mat[j+1][k] == 0 || mat[j+1][k] == mat[j][k])) {
						ans[0]++;
						ans[1] = 1; //DOWN
					}
					if (!ans[4] && j > 0 && (mat[j-1][k] == 0 || mat[j-1][k] == mat[j][k])) {
						ans[0]++;
						ans[4] = 1; //UP
					}
				}
				if (mat[j][k] == 2048) {
					ans[0] = 0;
					j = k = 4;
				}
			}

		if (!ans[0]) {
			printf("NONE\n");
		}
		else {
			if (ans[1]) {
				printf("DOWN");
				if (--ans[0]) printf(" ");
			}
			if (ans[2]) {
				printf("LEFT");
				if (--ans[0]) printf(" ");
			}
			if (ans[3]) {
				printf("RIGHT");
				if (--ans[0]) printf(" ");
			}
			if (ans[4])
				printf("UP");
			printf("\n");
		}
	}

	return 0;
}
