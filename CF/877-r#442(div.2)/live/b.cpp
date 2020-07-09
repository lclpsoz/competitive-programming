#include <bits/stdc++.h>
using namespace std;

const int MAXS = 5e3+10;

int i, j;
int arr[MAXS], maxi;
char str[MAXS], st;

int main (){

	scanf("%s", str);
	st = str[0];
	if (st == 'a') arr[0] = -1;
	else arr[0] = 1;

	for (i = 1, j = 0; i < strlen(str); i++){

		if (str[i] == 'a'){

			if (arr[j] > 0)
				j++;

			arr[j]--;

		}
		else{

			if (arr[j] < 0)
				j++;

			arr[j]++;

		}

	}

	maxi = 0;
	for (i = 0; i <= j; i++){

		printf("%d ", arr[i]);

		if (arr[i] < 0 && i < j-1)
			maxi = max(maxi, abs(arr[i]) + abs(arr[i+1]) + abs(arr[i+2]));

		if (i < j)
			maxi = max(maxi, abs(arr[i]) + abs(arr[i+1]));

		maxi = max(maxi, abs(arr[i]));

	}
	puts("");

	printf("%d\n", maxi);

	return 0;
}
