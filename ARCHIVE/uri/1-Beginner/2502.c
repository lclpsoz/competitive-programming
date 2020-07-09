#include <stdio.h>
#include <stdlib.h>

//The cipher can contain white spaces
//The cipher MUST BE case sensitive, so it's better to create and then replicate at the end of the array

int i, j, k, l;
int cipher_size, txt_qnt, aux, print;
char txt[1001];
char** cipher;

int main (void){

	while(scanf("%d %d", &cipher_size, &txt_qnt) != EOF){

		cipher = (char**) malloc(2 * sizeof(char*));

		cipher[0] = (char*) malloc((cipher_size + 1) * sizeof(char));
		cipher[1] = (char*) malloc((cipher_size + 1) * sizeof(char));

		for (i = 0; i < 2; i++)
			scanf(" %[^\n]", cipher[i]);

		for (i = 0; i < txt_qnt; i++){

			scanf(" %[^\n]", txt);

			for (j = 0; txt[j] != '\0'; j++){

				print = 0;
				for (k = 1; k < 3 && print == 0; k++)
					for (l = 0; l < cipher_size && print == 0; l++){

						if (txt[j] >= 'a' && txt[j] <= 'z' && txt[j] == (cipher[k - 1][l] - 'A' + 'a')){

							if (cipher[k % 2][l] >= 'A' && cipher[k % 2][l] <= 'Z')
								printf("%c", cipher[k % 2][l] - 'A' + 'a');
							else
								printf("%c", cipher[k % 2][l]);

							print = 1;

						}
						if (txt[j] == cipher[k - 1][l]){

							if (cipher[k - 1][l] >= 'A' && cipher[k - 1][l] <= 'Z')
								printf("%c", cipher[k % 2][l]);
							else
								printf("%c", cipher[k % 2][l] - 'A' + 'a');

							print = 1;

						}
					}

				if (print == 0)
					printf("%c", txt[j]);

			}

			printf("\n");

		}

		/*for (i = 0; i < 2; i++)
			for (j = 0; j < cipher_size; j++)
				printf("%c: %d\n", cipher[i][j], cipher[i][j]);*/

		free(cipher[0]);
		free(cipher[1]);
		free(cipher);

		printf("\n");

	}

	return 0;
}
