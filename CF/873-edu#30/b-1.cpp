#include <bits/stdc++.h>
using namespace std;

int const MAXS = 1e5+10;

int i, j;
int qnt;
int size, sum, l, r;
int arr[MAXS];
char str[MAXS];

int main (){

	scanf("%d", &qnt);
	scanf("%s", str);
	for (i = 0, j = 0; i < qnt;){

		if (!arr[j]){

			if (str[i]-'0') arr[j]++;
			else arr[j]--;
			i++;

		}
		else if (arr[j] > 0){

			if (str[i]-'0'){

			   arr[j]++;
			   i++;

			}
			else j++;

		}
		else{

			if (str[i]-'0') j++;
			else{

			   arr[j]--;
			   i++;

			}
		}

	}

	for (i = 0; arr[i]; i++){

		sum += arr[i];
		//printf("%d ", arr[i]);

	}
	l = 0;
	r = i-1;
	//printf("SUM: %d\n", sum);
	//printf("\n");

	while (sum && l <= r){

		while (sum > 0 && (arr[l] > 0 || arr[r] > 0)){

			if (arr[l] > 0) arr[l]--;
			else if (arr[r] > 0) arr[r]--;

			if (!arr[l]) l++;
			else if (!arr[r]) r--;


		}
		while (sum < 0 && (arr[l] < 0 || arr[r] < 0)){

			if (arr[l] < 0) arr[l]++;
			else if (arr[r] < 0) arr[r]++;

			if (!arr[l]) l++;
			else if (!arr[r]) r--;


		}
		if (arr[l] >




	}

	sum = 0;
	for (i = l; i <= r; i++) if (arr[i] > 0) sum += arr[i];

	puts(sum * 2);

	return 0;
}
