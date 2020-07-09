#include <stdio.h>

int frt, sec;

int main (void){

	scanf("%d %d", &frt, &sec);

	if (frt > sec)
		printf("%d\n", frt);
	else
		printf("%d\n", sec);

	return 0;
}
