#include <stdio.h>

int i;
int numb;

int main(void){

	scanf("%d", &numb);
	
	for (i = 0; i < numb;i++)
		if (numb % (i + 1) == 0)
			printf("%d\n", i + 1);

	return 0;
}
