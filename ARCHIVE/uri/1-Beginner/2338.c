#include <stdio.h>
#include <string.h>

int i, j, k, l, m;
int runs, code_size;
char code[1000], temp[5], morse[26][5] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

int main (void){

	scanf("%d", &runs);

	for (i = 0; i < runs; i++){

		memset(code, '\0', 1000);
		scanf("%s", code);
		code_size = strlen(code);

		for (j = 0; j <= code_size; j++){

			if (code[j] == '=')
				k++;
			else{

				if (k == 1)
					temp[l] = '.';
				else
					temp[l] = '-';

				k = 0;
				l++;

			}
			//printf("\t%d \t%c \t%d \t%s\n", j, code[j], l, temp);

			if ((code[j] == '.' && code[j + 1] == '.') || code[j] == '\0'){

				//printf("\t%d \t%c \t%d \t%s\n\n", j, code[j], l, temp);
				for (m = 0; m < 26; m++)
					if (!strcmp(morse[m], temp)){

						printf("%c", 97 + m);

						j += 2;
						memset(temp, '\0', 4);
						k = 0;
						l = 0;

						break;

					}
			}

			if (code[j] == '.' && code[j + 1] == '.' && code[j + 3] == '.'){

				printf(" ");

				j += 4;

			}

			if (code[j] == '\0'){

				printf("\n");
				break;

			}
		}
	}

	return 0;
}

