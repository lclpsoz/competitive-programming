#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e4, MAXN = 30;

int i;
int size, qnt, aux;
char str[MAXS], last;

int main (){

	while(scanf(" %[^\n]", str) != EOF){

		qnt = aux = 0;
		last = 1;
		size = strlen(str);
		for (i = 0; i < size; i++)
			if (!i || str[i-1] == ' '){

				if (tolower(str[i]) == last) aux = true;
				else if (aux){

					if (last > 1) qnt++;
					aux = false;

				}

				last = tolower(str[i]);
			}

		if (aux) qnt++;

		printf("%d\n", qnt);

	}

	return 0;
}
