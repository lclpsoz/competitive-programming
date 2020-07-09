#include <stdio.h>

int i;
int runs, nb1, nb2, ans;

int main (void){

	scanf("%d", &runs);
	scanf("%d", &nb1);

	for (i = 0; i < runs - 1 && ans == 0; i++){

		if (i != 0)
			nb1 = nb2;
		scanf("%d", &nb2);

		if (nb2 < nb1)
			ans = i + 2;

	}

	printf("%d\n", ans);

	return 0;
}
