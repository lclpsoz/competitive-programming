#include <bits/stdc++.h>
using namespace std;

int i;
int rest, rest_10, rest_total;
int numb;

int main (){

	while (scanf("%d", &numb) != EOF){

		i = 0;
		rest = rest_10 = rest_total = 0;

		rest = (int) pow(10, i++) % numb;
		rest_total = rest;

		if (rest){

			rest = rest_10 = (int) pow(10, i++) % numb;
			rest_total = (rest_total + rest) % numb;

			while (rest_total){

				i++;
				rest = (rest * rest_10) % numb;
				rest_total = (rest_total + rest) % numb;

			}
		}

		printf("%d\n", i);
	}

	return 0;
}
