#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+100;

int i;
char str[MAXN];

int main (){

	scanf("%[^\n]", str);

	while (str[i] != '\0'){

		if(str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] - 'A' + 'a';
		i++;

	}
	if(strstr(str, "zelda") == NULL)
		printf("Link Tranquilo\n");
	else
		printf("Link Bolado\n");

	return 0;
}
