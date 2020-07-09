#include <stdio.h>

int i;
int count;
char str[500];

int main (void){

	scanf("%s", str);
	for (i = 0; i < 500 && str[i] != '\0'; i++)
		if (str[i] == '1')
			count++;

	if (count % 2 == 0)
		printf("%s0\n", str);
	else
		printf("%s1\n", str);

	return 0;
}
