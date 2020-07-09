#include <stdio.h>
#include <stdlib.h>

int i, j, opr_i, opr_j;
int numb, med;

int print (int n){

	if (n > 9)
		printf(" %d ", n);
	else
		printf("  %d ", n);

}

int main (void){

	scanf("%d", &numb);
	med = numb / 2;

	while (numb > 0){

		for (i = 0; i < numb; i++)
			for (j = 0; j < numb; j++){
				
				if (i < med)
					opr_i = i + 1;
				else
					opr_i = numb - i;
				if (j < med)
					opr_j = j + 1;
				else
					opr_j = numb - j;

				if (j == numb - 1 && i == numb - 1)
					printf("  1\n\n");
				else if (j == (numb - 1))
					printf("  1\n");
				else if (opr_i <= opr_j)
					print(opr_i);
				else
					print(opr_j);

			}

		scanf("%d", &numb);
		med = numb / 2;

	}

	return 0;
}	
