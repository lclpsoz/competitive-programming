#include <stdio.h>
#include <stdlib.h>

int i, j, opr;
int numb;

int main (void){

	scanf("%d", &numb);

	while (numb > 0){

		for (i = 0; i < numb; i++)
			for (j = 0; j < numb; j++){
				
				opr = abs(i - j) + 1;

				if (opr > 99)
					printf("%d", opr);
				else if (opr > 9)
					printf(" %d", opr);
				else
					printf("  %d", opr);

				if (i == numb - 1 && j == numb - 1)
					printf("\n\n");
				else if (j == numb - 1)
					printf("\n");
				else
					printf(" ");

			}

		scanf("%d", &numb);

	}

	return 0;
}	
