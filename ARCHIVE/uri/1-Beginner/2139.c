#include <stdio.h>

int i;
int day, month, until, ar[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main (void){

	while (scanf("%d %d", &month, &day) != EOF){

		if (month != 12){

			for (i = month; i < 11; i++)
				until += ar[i];

			until += ar[month - 1] - day + 25;

			printf("Faltam %d dias para o natal!\n", until);

		}
		else if (day < 24)
			printf("Faltam %d dias para o natal!\n", 25 - day);
		else if (day == 24)
			printf("E vespera de natal!\n");
		else if (day == 25)
			printf("E natal!\n");
		else
			printf("Ja passou!\n");

		until = 0;
	}

	return 0;
}
