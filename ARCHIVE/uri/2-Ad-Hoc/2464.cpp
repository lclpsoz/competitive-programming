#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e4+10;

char cipher[30], c;

int main (){

	scanf(" %[^\n] ", cipher);

	c = getchar();
	while (c != EOF && c != '\n'){

		printf("%c", cipher[c-'a']);
		c = getchar();

	}
	printf("\n");

	return 0;
}
