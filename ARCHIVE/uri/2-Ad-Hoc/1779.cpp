#include <bits/stdc++.h>
using namespace std;

int i, j;
int qnt_a, qnt_b, val;
pair<int, int> maxi, aux;

int main (){

	scanf("%d", &qnt_a);
	for (i = 0; i < qnt_a; i++){

		aux = maxi = make_pair(-1, -1);
		scanf("%d", &qnt_b);
		for (j = 0; j < qnt_b; j++){

			scanf("%d", &val);
			if (val != aux.first){

				if (aux.first > maxi.first || (aux.first == maxi.first && aux.second > maxi.second)){

					maxi.first = aux.first;
					maxi.second = aux.second;

				}
				aux.first = val;
				aux.second = 1;

			}
			else if (val == aux.first)
				aux.second++;

		}
		if (aux.first > maxi.first){

			maxi.first = aux.first;
			maxi.second = aux.second;

		}
		else if (aux.first == maxi.first && aux.second > maxi.second)
			maxi.second = aux.second;

		printf("Caso #%d: %d\n", i+1, maxi.second);

	}

	return 0;
}
