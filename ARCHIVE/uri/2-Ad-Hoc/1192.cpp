#include <bits/stdc++.h>
using namespace std;

int i;
int qnt;
char str[4];

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%s", str);
		if (str[0] == str[2])
			printf("%d\n", (str[0]-'0')*(str[2]-'0'));
		else if (str[1] >= 'a' && str[1] <= 'z')
			printf("%d\n", str[0] + str[2] -'0' -'0');
		else
			printf("%d\n", str[2] - str[0] +'0' -'0');

	}

	return 0;
}
