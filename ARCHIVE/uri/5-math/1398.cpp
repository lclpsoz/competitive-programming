#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e7, MOD = 131071;

int j;
int i;
int size, rest, resp;
char aux[MAXS], str[MAXS];

int main (){

	while (scanf(" %[^#]#", aux) != EOF){

		resp = 0;

		i = 0;
		while (aux[i] == '0') i++;

		for (i = 0, j = 0; i < MAXS && aux[i] != '\0'; i++)
			if (aux[i] == '0' || aux[i] == '1') str[j++] = aux[i];

		size = strlen(str);
		//printf("%s\n", str);
		//printf("s: %d\n", size);

		rest = 1;
		if (str[size-1]-'0') resp += rest;
		str[size-1] = '\0';
		for (i = size-2; i >= 0; i--){

			rest *= 2;
			rest %= MOD;

			if (str[i]-'0'){

			   resp += rest;
			   resp %= MOD;

			}
			str[i] = '\0';
			//printf("%d %d\n", rest, resp);
		}

		if (resp) printf("NO\n");
		else printf("YES\n");
	}

	return 0;
}
