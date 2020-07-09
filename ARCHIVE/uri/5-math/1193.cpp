#include <bits/stdc++.h>
using namespace std;

int i, j, k;
int qnt, value, last;
char str[4], inp[50], bin[50];

int main (){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		value = 0;

		scanf("%s %s", inp, str);
		if (str[0] == 'b'){

			for (j = strlen(inp)-1, k = 0; j >= 0; j--, k++)
				value += pow(2, j) * (inp[k]-'0');

		}
		else if (str[0] == 'd')
			sscanf(inp, "%d", &value);
		else if (str[0] == 'h')
			sscanf(inp, "%x", &value);

		printf("Case %d:\n", i+1);
		if (str[0] != 'd')
			printf("%d dec\n", value);

		if (str[0] != 'h')
			printf("%x hex\n", value);

		if (str[0] != 'b'){

			last = floor(log2(value)) + 1;
			for(j = last-1; j >= 0; j--){

				bin[j] = (value % 2) + '0';
				value /= 2;

			}

			bin[last] = '\0';

			printf("%s bin\n", bin);

		}
		printf("\n");
	}

	return 0;
}
