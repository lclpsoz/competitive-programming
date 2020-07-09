#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e3+10;

int i, j;
int qnt, arr[30], ans;
char c;

int main (){

	scanf("%d ", &qnt);
	for (i = 0; i < qnt; i++){

		c = getchar();
		while (c != '\n'){

			if (c >= 'a' && c <= 'z')
				arr[c-'a']++;

			c = getchar();

		}
		ans = 0;
		for (j = 0; j <= ('z'-'a'); j++)
			if (arr[j]) ans++;

		if (ans == ('z'-'a'+1)) printf("frase completa\n");
		else if (ans >= (('z'-'a'+1)/2)) printf("frase quase completa\n");
		else printf("frase mal elaborada\n");

		memset(arr, 0, sizeof(arr));

	}

	return 0;
}
