#include <bits/stdc++.h>
using namespace std;

int i, j;
int size;
char aux[100], str[100];
bool test;

int main(){

	scanf("%s", aux);

	while (aux[j] != '\0'){

		if (aux[j] == 'a' || aux[j] == 'e' || aux[j] == 'i' || aux[j] == 'o' || aux[j] == 'u')
			str[i++] = aux[j];

		j++;
	}

	size = i;
	test = true;
	for (i = 0, j = size-1; i < size && j >= 0; i++, j--)
		if (str[i] != str[j])
			test = false;

	if (test) printf("S\n");
	else	printf("N\n");

	return 0;
}
