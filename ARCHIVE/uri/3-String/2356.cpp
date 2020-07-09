#include <bits/stdc++.h>
using namespace std;

const int MAXS = 150;

char str[MAXS], code[MAXS];

int main(){

	while (scanf("%s %s", str, code) != EOF){

		if (strstr(str, code) != NULL) printf("Resistente\n");
		else printf("Nao resistente\n");

	}

	return 0;
}
