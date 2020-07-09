#include <bits/stdc++.h>
using namespace std;

const int MAXS = 60;

int i, j;
int qnt;
char str1[MAXS], str2[MAXS];

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%s %s", str1, str2);

		for (j = 0; j < max(strlen(str1), strlen(str2)); j++){

			if (j < strlen(str1))
				printf("%c", str1[j]);

			if (j < strlen(str2))
				printf("%c", str2[j]);

		}
		printf("\n");
	}


	return 0;
}
