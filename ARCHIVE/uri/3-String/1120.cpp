#include <bits/stdc++.h>
using namespace std;

const int MAXS = 150;

int i;
int n;
char str[MAXS];
bool zero;

int main (){

	while (scanf("%d %s", &n, str), n || (str[0]-'0')){

		zero = true;
		for (i = 0; i < strlen(str); i++){

			if (str[i] != '0' && str[i] != (n+'0') && zero)
				zero = false;
			if ((str[i] != '0' || !zero) && str[i] != (n+'0'))
				printf("%c", str[i]);

		}
		if (zero) printf("0");
		printf("\n");

	}

	return 0;
}
