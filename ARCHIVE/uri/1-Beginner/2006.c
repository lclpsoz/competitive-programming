#include <stdio.h>

int i;
int numb, nb, count;

int main(void){

	scanf("%d", &numb);

	for (i = 0; i < 5; i++){

		scanf("%d", &nb);
		if (nb == numb)
			count++;

	}

	printf("%d\n", count);

	return 0;
}
