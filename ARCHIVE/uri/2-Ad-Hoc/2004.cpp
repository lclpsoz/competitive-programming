#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int i, j, k;
int qnt_test, qnt_foods, type, weight, sum;
int arr[MAXN];

int main (){

	scanf("%d", &qnt_test);

	for (i = 0; i < qnt_test; i++){

		scanf("%d", &qnt_foods);

		for (j = 0; j < qnt_foods; j++){

			scanf("%d %d", &type, &weight);

			//printf("bef: %d %d %d\n", type, weight, arr[type]);
			if (weight > arr[type] && !((arr[type] >= 10 && arr[type] <= 100) && weight > 100))
				arr[type] = weight;
			else if ((arr[type] < 10 ||  arr[type] > 100) && weight >= 10 && weight <= 100)
				arr[type] = weight;

			//printf("aft: %d %d %d\n", type, weight, arr[type]);

		}
		for (k = 1; k < 101; k++){

			sum += arr[k];
			arr[k] = 0;

		}

		printf("%d\n", sum);
		sum = 0;

	}
	return 0;
}
