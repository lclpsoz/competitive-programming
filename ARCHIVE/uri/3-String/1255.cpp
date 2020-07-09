#include <bits/stdc++.h>
using namespace std;

const int MAXS = 250;

int i, j;
int qnt, letters[30], maxi;
char str[MAXS], c;

int main (){

	scanf("%d ", &qnt);
	for (i = 0; i < qnt; i++){

		maxi = 0;
		c = getchar();
		while (c != '\n'){

			c = tolower(c);
			if (c >= 'a' && c <= 'z'){

				letters[c-'a']++;
				maxi = max(maxi, letters[c-'a']);

			}

			c = getchar();

		}

		for (j = 0; j <= 'z'-'a'; j++){

			if (letters[j] == maxi)
				printf("%c", j+'a');

			letters[j] = 0;

		}
		printf("\n");


	}

	return 0;
}
