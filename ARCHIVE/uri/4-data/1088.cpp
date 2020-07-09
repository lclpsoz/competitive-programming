//Implementation using merge sort to count amount of 'swaps' needed to order an array
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int conquer (int l_lim, int r_lim, int *arr, int *aux, int *resp){

	//printf("C: %d %d\n", l_lim, r_lim);
	int mid = (l_lim + r_lim) / 2;
	int l = l_lim, r = mid+1, i, j;

	i = l_lim;
	while (l <= mid && r <= r_lim){

		if (arr[l] <= arr[r]){

			aux[i++] = arr[l++];

		}
		else{

			*resp += abs(r - i);
			aux[i++] = arr[r++];

		}
	}

	while (l <= mid){

		aux[i++] = arr[l++];

	}

	while (r <= r_lim){

		aux[i++] = arr[r++];

	}

	for (i = l_lim; i <= r_lim; i++)
		arr[i] = aux[i];

	//for (j = 0; j < 7; j++) printf("%d ", arr[j]);
	//printf("\n\n");

}

int divide (int l, int r, int *arr, int *aux, int *resp){

	int mid;

	if (l < r){

		//printf("D: %d %d\n", l, r);
		mid = (l + r) / 2;
		divide(l, mid, arr, aux, resp);
		divide(mid+1, r, arr, aux, resp);

		conquer(l, r, arr, aux, resp);

	}
}

int main (){

	int i;
	int qnt, resp;
	int arr[MAXN], aux[MAXN];

	scanf("%d", &qnt);
	while (qnt){

		resp = 0;
		for (i = 0; i < qnt; i++)
			scanf("%d", &arr[i]);

		divide(0, qnt-1, arr, aux, &resp);
		if (resp % 2 == 0) printf("Carlos\n");
		else printf("Marcelo\n");

		/*for (i = 0; i < qnt; i++)
			printf("%d\n", arr[i]);
		printf("\n");*/

		scanf("%d", &qnt);
	}


	return 0;
}
