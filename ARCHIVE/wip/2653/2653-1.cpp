#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e8;

int i, j;
int qnt;
char str[MAXN], sub_str[MAXN];


int main(){

	i = 0;//str position
	j = 0;
	sub_str[0] = ' ';
	while (scanf("%s", &sub_str[1]) != EOF){

		j = strlen(sub_str);
		sub_str[j] = ' ';
		sub_str[j+1] = '\0';

		j = 0;//Counter of sub_string position
		if (strstr(str, sub_str) == NULL){

			qnt++;
			while (sub_str[j] != '\0')
				str[i++] = sub_str[j++];

		}

		//printf("%s\n", str);

	}

	printf("%d\n", qnt);

	return 0;
}
