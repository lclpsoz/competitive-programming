#include <stdio.h>

int i;
int amnt, force;
char st[100];

int main (void){

	scanf("%d", &amnt);

	for (i = 0; i < amnt; i++){

		scanf("%s %d", st, &force);

		if (st[0] == 'T' && st[1] == 'h' && st[2] == 'o' && st[3] == 'r' && st[4] == '\0')
			printf("Y\n");
		else
			printf("N\n");

	}

	return 0;
}
