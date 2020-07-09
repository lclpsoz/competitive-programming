#include <stdio.h>

int i;
char str[500];

int main (void){

	scanf("%[^\n]s", str);

	for (i = 0; i < 500; i++)
		if (str[i] == '\0')
			break;

	if (i > 140)
		printf("MUTE\n");
	else
		printf("TWEET\n");

	return 0;
}
