#include <stdio.h>

int i, j;
char win[3][100] = {"Os atributos dos monstros vao ser inteligencia, sabedoria...", "Iron Maiden's gonna get you, no matter how far!", "Urano perdeu algo muito precioso..."};
char tie[100] = "Putz vei, o Leo ta demorando muito pra jogar...";
char game[3][10];
int print, aux;

int main (void){

	while (scanf("%s %s %s", game[0], game[1], game[2]) != EOF){

		//printf("%c %c %c\n", game[0][2], game[1][2], game[2][2]);
		print = 1;
		for (i = 0; i < 3 && print; i++){

			if (game[i][2] == 'd'){

				aux = 0;
				for (j = 0; j < 3; j++)
					if (j != i && game[j][2] == 's')
						aux++;

				if (aux == 2){

					//printf("d\t");
					printf("%s\n", win[i]);
					print = 0;

				}
			}
			else if (game[i][2] == 'p'){

				aux = 0;
				for (j = 0; j < 3; j++)
					if (j != i && game[j][2] == 'd')
						aux++;

				if (aux == 2){

					//printf("p\t");
					printf("%s\n", win[i]);
					print = 0;

				}
			}
			else if (game[i][2] == 's'){

				aux = 0;
				for (j = 0; j < 3; j++)
					if (j != i && game[j][2] == 'p')
						aux++;

				if (aux == 2){

					//printf("s\t");
					printf("%s\n", win[i]);
					print = 0;

				}
			}
		}
		if (print)
			printf("%s\n", tie);
	}

	return 0;
}
