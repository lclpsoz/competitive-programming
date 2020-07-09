#include <stdio.h>

int numb, pos, count;

int main (void){

	scanf("%d", &numb);

	do{

		if ((pos * 2) + 1 < numb)
			pos = (pos * 2) + 1;
		else
			pos = (pos - (numb / 2)) * 2;

		count++;

	}while (pos != 0);

	printf("%d\n", count);

	return 0;
}
