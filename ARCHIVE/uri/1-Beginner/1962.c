#include <stdio.h>

int i, amnt;
long long unsigned int numb;

int main (void){

	scanf("%d", &amnt);

	for (i = 0; i < amnt; i++){

		scanf("%lld", &numb);
		if (numb < 2015)
			printf("%lld D.C.\n", 2015 - numb);
		else
			printf("%lld A.C.\n", numb - 2014);

	}

	return 0;
}
