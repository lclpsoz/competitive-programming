#include <bits/stdc++.h>
using namespace std;

const int MAXS = 150;

int i, j;
int size, aux;
char str[MAXS];

int main(){

	while (scanf("%s", str) != EOF){

		size = aux = strlen(str);

		for (i = 0; i < size; i++){

			for (j = 0; j < i; j++)
				printf(" ");

			for (j = 0; str[j] != '\0'; j++)
				if (str[j+1] != '\0') printf("%c ", str[j]);
				else printf("%c", str[j]);

			printf("\n");
			str[--aux] = '\0';

		}
		printf("\n");
	}

	return 0;
}
