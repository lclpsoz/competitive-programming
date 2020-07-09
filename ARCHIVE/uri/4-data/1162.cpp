#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int i, j;
int qnt_tests, qnt_cars;

int bubble (int *arr, int size){

	int i, j;
	int aux, swaps = 0;

	for (i = 0; i < size-1; i++)
		for (j = i+1; j < size && arr[i] != i+1; j++){
			if (arr[i] > arr[j]){

				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
				swaps++;

			}
		}

	return swaps;

}

int main (){

	int arr[MAXN];

	scanf("%d", &qnt_tests);
	for (i = 0; i < qnt_tests; i++){

		scanf("%d", &qnt_cars);
		for (j = 0; j < qnt_cars; j++)
			scanf("%d", &arr[j]);

		printf("Optimal train swapping takes %d swaps.\n", bubble(arr, qnt_cars));


	}

	return 0;
}
