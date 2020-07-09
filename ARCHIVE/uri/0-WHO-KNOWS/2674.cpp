#include <bits/stdc++.h>
using namespace std;

int i, j;
int numb, digit;
bool test;

int main(){

	while (scanf("%d", &numb) != EOF){

		test = true;
		for (i = 2; i*i <= numb; i++)
			if (numb % i == 0)
				test = false;

		if (numb == 1)
			test = false;

		if (test){

			while (numb > 0){

				digit = numb % 10;
				numb /= 10;
				if (digit == 0 || digit == 1)
					test = false;
				for (i = 2; i*i <= digit; i++)
					if (digit % i == 0)
						test = false;

			}

			if (test)
				printf("Super\n");
			else
				printf("Primo\n");

		}
		else
			printf ("Nada\n");

	}

	return 0;
}
