#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e3+10;

int i, j;
int qnt, size, opens, resp;
char str[MAXS];

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%s", str);
		opens = resp = 0;
		size = strlen(str);
		for (j = 0; j < size; j++){

			if (str[j] == '<') opens++;
			else if (opens > 0 && str[j] == '>'){

				opens--;
				resp++;

			}
		}

		printf("%d\n", resp);

	}

	return 0;
}
