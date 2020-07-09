#include <bits/stdc++.h>
using namespace std;

const int MAXS = 60;

int i;
char str[MAXS], c;

int main (){

	while (scanf("%[^\n]", str) != EOF){

		c = getchar();

		for (i = 0; i < strlen(str); i++){

			if (str[i] >= 'a' && str[i] <= 'z'){

				str[i] = ((str[i]-'a'+13) % ('z'-'a'+1)) + 'a';


			}
			else if (str[i] >= 'A' && str[i] <= 'Z'){

				str[i] = ((str[i]-'A'+13) % ('Z'-'A'+1)) + 'A';

			}
			printf("%c", str[i]);

		}
		printf("\n");

	}

	return 0;
}
