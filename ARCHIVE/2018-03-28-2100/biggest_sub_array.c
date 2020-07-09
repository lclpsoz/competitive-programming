//Algorithm that returns the biggest sub array of a especific array (the interval and sum)
#include <stdio.h>

#define MAXN 10000


int big_sub (int* arr, int l, int r, int* l_big, int* r_big, int* size_big){

	int mid = (l + r)/2;

	if (l < r){

		int a = big_sub (arr, l, mid, l_big, r_big, size_big);


	}

}

int main (void){

	int i;
	int arr[MAXN];

	for (i = 0; i < MAXN; i++){


	}

	return 0;
}
