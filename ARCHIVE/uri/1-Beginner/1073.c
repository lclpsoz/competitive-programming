#include <stdio.h>
#include <math.h>

int main(){

	int i;
	int numb, ans;
	scanf("%d", &numb);

	for (i = 1; i <= numb;i++){

		ans = pow(i, 2);
		if (i % 2 == 0)
			printf("%d^2 = %d\n", i, ans);

	}

	return 0;
}
