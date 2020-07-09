#include <stdio.h>

int i;
char str[500];

int main (void){

	scanf("%[^\n]s", str);

	for (i = 0; i < 500; i++)
		if (str[i] == '\0')
			break;

	if (i > 80)
		printf("NO\n");
	else
		printf("YES\n");

	return 0;
}
