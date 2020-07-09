#include <bits/stdc++.h>
using namespace std;

const int MAXS = 60;

int i, j;
int qnt;
char str[MAXS], c;

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		c = getchar();
		scanf("%[^\n]", str);
		//printf("S:%s\n", str);

		if (str[0] != ' ')
			printf("%c", str[0]);
		for (j = 1; j < strlen(str); j++)
			if (str[j] != ' ' && str[j-1] == ' ')
				printf("%c", str[j]);
		printf("\n");

	}

	return 0;
}
