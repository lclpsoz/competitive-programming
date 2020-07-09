#include <stdio.h>

int main(){

	int i;
	int qnt, numb, in = 0, out = 0;
	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){
		
		scanf("%d", &numb);

		if (numb >= 10 && numb <= 20)
			in++;
		else
			out++;

	}

	printf("%d in\n%d out\n", in, out);

	return 0;
}
