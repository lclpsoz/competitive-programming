#include <stdio.h>

int i, j, pa, im;
int numb, par[5], impar[5];

int main (void){

	for (i = 0; i < 15; i++){

		scanf("%d", &numb);
		if (numb % 2 == 0){

			par[pa] = numb;
			pa++;

			if (pa == 5){
		
				for (j = 0; j < 5; j++)
					printf("par[%d] = %d\n", j, par[j]);
		
				pa = 0;
			
			}	
		}
		else{

			impar[im] = numb;
			im++;

			if (im == 5){

				for (j = 0; j < 5; j++)
					printf("impar[%d] = %d\n", j, impar[j]);

				im = 0;

			}
		}
	}

	for (i = 0; i < im; i++)
		printf("impar[%d] = %d\n", i, impar[i]);
	for (i = 0; i < pa; i++)
		printf("par[%d] = %d\n", i, par[i]);

	return 0;
}
