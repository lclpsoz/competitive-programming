#include <stdio.h>

int main(){

	int code, amount;
	double cost;
	scanf("%d%d", &code, &amount);

	if(code == 1){

		cost = amount * 4;
		printf("Total: R$ %0.2lf\n", cost);

	}
	else if(code == 2){

		cost = amount * 4.5;
		printf("Total: R$ %0.2lf\n", cost);

	}
	else if(code == 3){

		cost = amount * 5;
		printf("Total: R$ %0.2lf\n", cost);

	}
	else if(code == 4){

		cost = amount * 2;
		printf("Total: R$ %0.2lf\n", cost);

	}
	else if(code == 5){

		cost = amount * 1.5;
		printf("Total: R$ %0.2lf\n", cost);

	}

	return 0;
}