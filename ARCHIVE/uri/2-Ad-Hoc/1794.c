#include <stdio.h>

int i;
int val, lim[4];

int main (void){

	scanf("%d", &val);

	for (i = 0; i < 4; i++)
		scanf("%d", &lim[i]);

	if (val >= lim[0] && val <= lim[1] && val >= lim[2] && val <= lim[3])
		printf("possivel\n");
	else
		printf("impossivel\n");

	return 0;
}
