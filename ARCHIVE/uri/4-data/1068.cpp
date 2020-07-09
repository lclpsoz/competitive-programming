#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e3+10;

int i;
int size, resp;
char str[MAXS];

int main (){

	while (scanf("%s", str) != EOF){

		resp = 0;
		size = strlen(str);

		for (i = 0; i < size; i++){

			if (str[i] == '(') resp++;
			else if (str[i] == ')') resp--;

			if (resp < 0) break;

		}

		if (resp) printf("incorrect\n");
		else printf("correct\n");


	}

	return 0;
}
