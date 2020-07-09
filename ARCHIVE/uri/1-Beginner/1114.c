#include <stdio.h>

int main(){

	int pw = 0;
	scanf("%d", &pw);

	while (pw != 2002){

		printf("Senha Invalida\n");

		scanf("%d", &pw);

	}

	printf("Acesso Permitido\n");

	return 0;
}
