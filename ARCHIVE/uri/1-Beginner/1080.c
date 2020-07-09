#include <stdio.h>

int main(){

	int i;
	int numb, max = 0, pos;

	for (i = 0; i < 100; i++){
		
		scanf("%d", &numb);
		
		if (numb > max){

			max = numb;
			pos = i + 1;

		}
	}

	printf("%d\n%d\n", max, pos);
}
