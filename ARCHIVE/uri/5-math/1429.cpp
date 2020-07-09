#include <bits/stdc++.h>
using namespace std;

int i, j;
int fat[6], val;
char str[100];

int main (){

	fat[0] = 1;
	for (i = 1; i < 7; i++)
		fat[i] = fat[i-1] * i;

	scanf("%s", str);

	while (str[0]-'0'){

		val = 0;
		for (i = strlen(str)-1, j = 1; i >= 0; i--, j++)
			val += (str[i]-'0') * fat[j];

		printf("%d\n", val);

		scanf("%s", str);
	}

	return 0;
}
