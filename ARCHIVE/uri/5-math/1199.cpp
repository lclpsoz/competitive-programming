#include <bits/stdc++.h>
using namespace std;

int i;
char str[50];
unsigned int value;

int main(){

	scanf("%s", str);

	while (str[0] != '-'){

		if (str[1] == 'x'){

			sscanf(str, "%x", &value);
			printf("%d\n", value);

		}
		else{

		   sscanf(str, "%d", &value);
		   printf("0x%X\n", value);

		}
		scanf("%s", str);

	}

	return 0;
}
