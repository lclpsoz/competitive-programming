#include <stdio.h>
#include <math.h>

int i;
unsigned long long int numb1, numb2, resp;
char str1[32], str2[32], result[32];

int main (void){

	while (scanf("%lld %lld", &numb1, &numb2) != EOF){

		i = 31;
		while (numb1 > 1){

			str1[i--] = numb1 % 2;
			numb1 /= 2;

		}
		str1[i] = numb1;

		i = 31;
		while (numb2 > 1){

			str2[i--] = numb2 % 2;
			numb2 /= 2;

		}
		str2[i] = numb2;

		for (i = 0; i < 32; i++){

			result[i] = 0;
			if (str1[i] != str2[i])
				result[i] = 1;

			str1[i] = 0;
			str2[i] = 0;

		}

		resp = 0;
		for (i = 0; i < 32; i++)
			resp += result[i] * pow(2, 31 - i);

		printf("%lld\n", resp);

		/*for(i = 0; i < 32; i++){

			printf("%d", str[i]);
			str[i];

		}

		printf("\n");*/
	}

	return 0;
}
