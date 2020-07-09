#include <stdio.h>
#include <math.h>

int one_digit (int num){

	int i;
	int size = 0, aux = num, sum = 0;

	while (aux > 0){

		aux /= 10;
		size++;

	}

	for (i = 0; i < size; i++){

		aux = (num / 10) * 10;
		sum += num - aux;
		num /= 10;

	}
	if (sum > 9)
		one_digit(sum);
	else
		return sum;
}

int main (void){

	int i;
	int num1, num2;
	char str1[111], str2[111];
	scanf("%s %s", str1, str2);

	while (str1[0] != '0' || str2[0] != '0'){

		num1 = 0;
		num2 = 0;
		i = 0;
		while (str1[i] != '\0')
			num1 += str1[i++] - '0';

		i = 0;
		while (str2[i] != '\0')
			num2 += str2[i++] - '0';

		num1 = one_digit(num1);
		num2 = one_digit(num2);

		if (num1 > num2)
			printf("1\n");
		else if (num2 > num1)
			printf("2\n");
		else
			printf("0\n");

		scanf("%s %s", str1, str2);
	}

	return 0;
}
