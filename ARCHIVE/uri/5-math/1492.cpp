#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;
const int MAXN = 60;

int i;
int size;
char str[MAXN];
llu a, b;
llu qnt_aux, qnt_a, qnt_b;	//Quantity of '1' until a and until b-1 (so excluding b)
llu arr[MAXN];	//Contains the amount of '1' in binary from 1 to the power of two of the corresponding position, position 0 → 2^0, 1 → 2^1, 2 → 2^2 and so on.

int main (){

	arr[0] = 1;
	for (i = 1; i < MAXN; i++){

		arr[i] = 2*arr[i-1] + (1LLU << (i-1)) - 1;
		//printf("%d\t%llu\n", i, arr[i]);

	}

	while (scanf("%llu %llu", &a, &b) != EOF){

		qnt_a = qnt_b = 0;
		//Calculate qnt_a:
		a--; //Because the interval is closed, it includes the number inputed
		i = 0;
		qnt_aux = a; //To subtract the next qnt, and so get the 'extras' '1', from after the sequence (ex: 9 → 1001, that would be all values until 2^3 + 1 + 2^0, that +1 is 9-2^3 = 1.
		while (a > 0){

			if (a % 2) str[i++] = '1';
			else str[i++] = '0';
			a /= 2;

		}
		size = strlen(str);
		//printf("%s\n", str);

		for (i = size-1; i >= 0; i--){

			if (str[i]-'0'){

				qnt_aux -= (1LLU << i);
				qnt_a += arr[i] + qnt_aux;


			}
			str[i] = '\0';

		}

		//Calculate qnt_b:
		i = 0;
		qnt_aux = b;
		while (b > 0){

			if (b % 2) str[i++] = '1';
			else str[i++] = '0';
			b /= 2;

		}
		size = strlen(str);
		//printf("%s\n", str);

		for (i = size-1; i >= 0; i--){

			if (str[i]-'0'){

				qnt_aux -= (1LLU << i);
				qnt_b += arr[i] + qnt_aux;


			}
			str[i] = '\0';

		}

		printf("%llu\n", qnt_b - qnt_a);

	}

	return 0;
}
