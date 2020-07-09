#include <stdio.h>
#include <math.h>

int i, j;
int a, b, c;
char str[30];

int main (void){

	do{

		a = 0;
		b = 0;
		c = 0;
		scanf("%s", str);

		i = 0;
		while (str[i] != '+')
			a += (str[i] - '0') * pow(10, i++);

		i++;
		j = 0;
		while (str[i + j] != '=')
			b += (str[i + j] - '0') * pow(10, j++);

		i += j + 1;
		j = 0;
		while (str[i + j] != '\0')
			c += (str[i + j] - '0') * pow(10, j++);

		if (a + b != c)
			printf("False\n");
		else
			printf("True\n");

	}while(!(str[0] == '0' && str[2] == '0' && str[4] == '0' && str[5] == '\0'));

	return 0;
}
