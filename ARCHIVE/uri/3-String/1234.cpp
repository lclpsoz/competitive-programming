#include <bits/stdc++.h>
using namespace std;

const int MAXS = 60;

int i, j;
char str[MAXS], c;

int main (){

	while(scanf("%[^\n]", str) != EOF){

		c = getchar();
		for (i = 0, j = 0; i < strlen(str); i++){

			if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){

				if (j % 2){

					printf("%c", tolower(str[i]));

				}
				else
					printf("%c", toupper(str[i]));

				j++;

			}
			else
				printf("%c", str[i]);

		}
		printf("\n");

	}

	return 0;
}
