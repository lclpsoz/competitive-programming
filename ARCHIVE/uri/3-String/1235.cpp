#include <bits/stdc++.h>
using namespace std;

const int MAXS = 150;

int i, j;
int qnt;
char str[MAXS], c;

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		c = getchar();
		scanf("%[^\n]", str);

		for (j = (strlen(str)/2)-1; j >= 0; j--)
			printf("%c", str[j]);

		for (j = strlen(str)-1; j >= strlen(str)/2; j--)
			printf("%c", str[j]);

		printf("\n");

	}

	return 0;
}
