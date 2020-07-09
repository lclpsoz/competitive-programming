#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e5+10;

int i, j;
int qnt, change;
char str[MAXS];

int main (){

	while (scanf(" %d %d %s ", &qnt, &change, str), qnt || change){


		j = 0;
		while (change){

			i = 0;
			while (str[i] < str[i+1] && change){

				str[i++] = 'A';
				change--;

			}

			for (i = 0; i < qnt && change; i++){

				if (str[i] == j+'0'){

					str[i] = 'A';
					change--;

				}

				if ((i+1) < qnt && str[i] < str[i+1])
					break;

			}
			j++;
			printf("%s\n", str);
				for (int k=0; k < 1e8; k++);

		}

		for (i = 0; i < qnt; i++)
			if (str[i] != 'A')
				printf("%c", str[i]);
		printf("\n");

	}

	return 0;
}
