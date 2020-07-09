#include <stdio.h>

int main(void){

	int i, numb, even = 0, odd = 0, pos = 0, neg = 0;
	scanf("%d", &numb);

	for (i = 1; i <= numb; ++i){
		
		if (i % 2 != 0)
			printf("%d\n", i);

	}

	return 0;
}