#include <stdio.h>

int i;
int n, nb1, nb2, sq, test = 1;

int main (void){

	scanf("%d", &n);
	scanf("%d", &nb1);

	for (i = 0; i < (n - 1); i++){

		if (i == 0)
			scanf("%d", &nb2);
		else{

			nb1 = nb2;
			scanf("%d", &nb2);

		}

		if (nb1 > nb2 && (sq == 2 || sq == 0))
			sq = 1;
		else if (nb1 < nb2 && (sq == 1 || sq == 0))
			sq = 2;
		else
			test = 0;

	}

	printf("%d\n", test);

	return 0;
}
