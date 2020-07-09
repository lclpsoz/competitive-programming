#include <stdio.h>

void swp(int* a, int* b){

	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

int main(){

	int i;
	int n1, n2, sum;
	scanf("%d %d", &n1, &n2);
	if (n1 > n2)
		swp(&n1, &n2);


	while (n1 > 0 && n2 > 0){

		for (i = n1; i <= n2; i++){

			printf("%d ", i);
			
			sum += i;
		
		}
		
		printf("Sum=%d\n", sum);
		sum = 0;

		scanf("%d %d", &n1, &n2);
		if (n1 > n2)
			swp(&n1, &n2);

	}


	return 0;
}
