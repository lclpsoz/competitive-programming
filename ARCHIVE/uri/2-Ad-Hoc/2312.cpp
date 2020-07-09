#include <bits/stdc++.h>
using namespace std;

const int MAXN = 600, MAXL = 1001;

int i, j;
int qnt, medals[MAXN][3], aux_int;
char mat_str[MAXN][MAXL], aux[MAXL];

int swp(){

	int k;
	for (k = 0; k < 3; k++){

		aux_int = medals[i][k];
		medals[i][k] = medals[j][k];
		medals[j][k] = aux_int;

	}

	strcpy(aux, mat_str[i]);
	strcpy(mat_str[i], mat_str[j]);
	strcpy(mat_str[j], aux);

}

int main(){

	int k, l;

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++)
		scanf("%s %d %d %d", mat_str[i], &medals[i][0], &medals[i][1], &medals[i][2]);

	for (i = 0; i < qnt-1; i++)
		for (j = i+1; j < qnt; j++){

			if (medals[i][0] < medals[j][0]){

				swp();

			}
			else if (medals[i][0] == medals[j][0]){

				if (medals[i][1] < medals[j][1]){

					swp();

				}
				else if (medals[i][1] == medals[j][1]){

					if (medals[i][2] < medals[j][2]){

						swp();

					}
					else if (medals[i][2] == medals[j][2] && strcmp(mat_str[i], mat_str[j]) > 0){

						swp();

					}
				}
			}

			/*for (k = 0; k < qnt; k++){

				for (l = 0; l < 3; l++)
					printf("%d ", medals[k][l]);
				printf("\n");

			}
			printf("\n");*/

		}


	/*for (i = 0; i < qnt-1; i++)
		for (j = i+1; j < qnt; j++)
			if (strcmp(mat_str[i][1], mat_str[j][1]) > 0){

				strcpy(aux, mat_str[i][1]);
				strcpy(mat_str[i][1], mat_str[j][1]);
				strcpy(mat_str[j][1], aux);

			}*/

	for (i = 0; i < qnt; i++)
		printf("%s %d %d %d\n", mat_str[i], medals[i][0], medals[i][1], medals[i][2]);

	return 0;
}
