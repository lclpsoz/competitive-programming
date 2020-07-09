//Implementation using merge sort to count amount of 'swaps' needed to order an array
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

void conquer (int l_lim, int r_lim, int *arr, int *aux, long long *resp){
	int mid = (l_lim + r_lim) / 2;
	int l = l_lim, r = mid+1, i, j;

	i = l_lim;
	while (l <= mid && r <= r_lim) {

		if (arr[l] <= arr[r])
			aux[i++] = arr[l++];
		else {
			*resp += abs(r - i);
			aux[i++] = arr[r++];
		}
	}

	while (l <= mid)
		aux[i++] = arr[l++];

	while (r <= r_lim)
		aux[i++] = arr[r++];

	for (i = l_lim; i <= r_lim; i++)
		arr[i] = aux[i];
}

void divide (int l, int r, int *arr, int *aux, long long *resp){

	long long mid;

	if (l < r) {
		mid = (l + r) / 2;
		divide(l, mid, arr, aux, resp);
		divide(mid+1, r, arr, aux, resp);

		conquer(l, r, arr, aux, resp);
	}
}

int main (){
	int qnt;
	long long resp;
	int arr[MAXN], aux[MAXN];

	while (scanf("%d", &qnt) != EOF) {

		resp = 0;
		for (int i = qnt-1; i >= 0; i--)
			scanf("%d", &arr[i]);

		divide(0, qnt-1, arr, aux, &resp);
		printf ("%lld\n", resp);
	}


	return 0;
}
