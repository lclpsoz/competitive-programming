#include <stdio.h>

long long int numb, resp;

int main (void){

	scanf("%lld", &numb);
	resp = ((numb - 3) * numb) / 2;
	printf("%lld\n", resp);

	return 0;
}
