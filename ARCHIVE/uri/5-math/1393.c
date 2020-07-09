#include <stdio.h>

int numb, ar[41], func[40];

int main (void){

	int i;
	ar[0] = 0;
	ar[1] = 1;
	for (i = 2; i < 41; i++)
		ar[i] = ar[i - 2] + ar[i - 1];

	for (i = 0; i < 40; i++)
		func[i] = ar[i] + ar[i + 1];

	scanf("%d", &numb);
	while (numb != 0){

		printf("%d\n", func[numb - 1]);
		scanf("%d", &numb);

	}

	return 0;
}
