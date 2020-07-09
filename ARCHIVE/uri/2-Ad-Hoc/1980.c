#include <stdio.h>
#include <string.h>

int i;
long long int val;
char str[200];

int main (void){

	scanf("%s", str);

	while (str[0] != '0' || str[1] != '\0'){

		val = 1;

		for (i = strlen(str); i > 0; i--)
			val *= i;
		printf("%lld\n", val);

		scanf("%s", str);

	}

	return 0;
}
