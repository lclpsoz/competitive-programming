#include <stdio.h>

int inv(int* a, int* b){

	int c;
	c = *a;
	*a = *b;
	*b = c;

}

int main(void){

	int i, numb1, numb2, sum = 0;
	scanf("%d\n%d", &numb1, &numb2);
	if (numb1 > numb2)
		inv(&numb1, &numb2);

	for (i = (numb1 + 1); i < numb2; ++i){
		if (i % 2 != 0)
			sum += i;

	}

	printf("%d\n", sum);

	return 0;
}