#include <stdio.h>
#include <string.h>

int main(){

	int i;
	char DDD[2] = { '\0' }, * table[8][2] = {
		{"61", "Brasilia"}, {"71", "Salvador"},
		{"11", "Sao Paulo"}, {"21", "Rio de Janeiro"},
		{"32", "Juiz de Fora"}, {"19", "Campinas"},
		{"27", "Vitoria"}, {"31", "Belo Horizonte"}		};
	scanf("%2s", DDD);

	for (i = 0; i < 8; ++i)	{
		
		if (strcmp(DDD, table[i][0]) == 0){

			printf("%s\n", table[i][1]);
			break;

		}
		else if (strcmp(table[i][0], "31") == 0){

			printf("DDD nao cadastrado\n");
			break;

		}
	}

	return 0;
}