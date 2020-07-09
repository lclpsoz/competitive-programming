#include <bits/stdc++.h>
using namespace std;

int i, j;
char str[100000], str_input[100000], c;

int main (void){

	strcpy(str, "`1234567890-= QWERTYUIOP[]\\ ASDFGHJKL;' ZXCVBNM,./");
	//printf("%s\n", str);

	while (scanf("%[^\n]", str_input) != EOF){

		scanf("%c", &c);
		for (i = 0; i < strlen(str_input); i++){

			if (str_input[i] == ' ')
				printf(" ");
			else{

				for (j = 0; j < 55 && str[j] != str_input[i]; j++);
				printf("%c", str[j-1]);

			}

		}
		printf("\n");

	}

	return 0;

}
