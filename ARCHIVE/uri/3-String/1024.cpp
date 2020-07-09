#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e4+100;

int i, j, k;
int qnt, half;
char c, str[MAXS], resp[MAXS];

int main (){

	scanf("%d ", &qnt);
	for (k = 0; k < qnt; k++){

		c = getchar_unlocked();
		i = 0;
		while (c != '\n'){

			str[i++] = c;
			c = getchar_unlocked();

		}
		str[i] = '\0';

		half = i / 2;

		for (i = strlen(str)-1, j = 0; i >= 0; i--, j++){

			if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
				resp[j] = str[i] + 3;
			else
				resp[j] = str[i];
			if (j >= half)  resp[j]--;

		}
		resp[j] = '\0';
		printf("%s\n", resp);

	}

	return 0;
}
