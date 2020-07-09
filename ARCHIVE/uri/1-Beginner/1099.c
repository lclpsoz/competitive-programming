#include <stdio.h>

void swp(int* a, int* b){
	
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;

}

int main(){

	int i, j;
	int qnt, sum = 0;
	scanf("%d", &qnt);
	int range[qnt][2];
	
	for (i = 0; i < qnt; i++){
		
		scanf("%d %d", &range[i][0], &range[i][1]);
		if (range[i][0] > range[i][1])
			swp(&range[i][0], &range[i][1]);

	}

	for (i = 0; i < qnt; i++){
		
		for (j = (range[i][0] + 1); j < range[i][1]; j++)
			if (j % 2 != 0)
				sum += j;
		
		printf("%d\n", sum);
		sum = 0;

	}

	return 0;
}
