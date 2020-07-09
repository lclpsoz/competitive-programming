#include <stdio.h>

int alc, gas, die, ans;

int main(void){

	scanf("%d", &ans);
	while(ans != 4){

		switch (ans){
			case 1:
				alc++;
				break;
			case 2:
				gas++;
				break;
			case 3:
				die++;
				break;
		}
		scanf("%d", &ans);

	}
	printf("MUITO OBRIGADO\n");
	printf("Alcool: %d\n", alc);
	printf("Gasolina: %d\n", gas);
	printf("Diesel: %d\n", die);

	return 0;
}
