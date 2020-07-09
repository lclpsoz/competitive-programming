#include <stdio.h>

int a, b, c, var_1, var_2;

int main (void){

	scanf("%d %d %d", &a, &b, &c);

	var_1 = b - a;
	var_2 = c - b;

	if (var_1 < 0)
		if (var_2 <= var_1)
			printf(":(\n");
		else if ((var_2 >= 0) || (var_2 > var_1))
			printf(":)\n");

	if (var_1 > 0)
		if ((var_2 <= 0) || (var_2 < var_1))
			printf(":(\n");
		else if (var_2 >= var_1)
			printf(":)\n");

	if (var_1 == 0)
		if (var_2 > 0)
			printf(":)\n");
		else
			printf(":(\n");

	return 0;
}
