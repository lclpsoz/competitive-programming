#include <bits/stdc++.h>
using namespace std;

int i, j;
int qnt, arr[6], test;

int main (){

	scanf("%d", &qnt);
	for (j = 0; j < qnt; j++){

		for (i = 0; i < 6; i++)
			scanf("%d", &arr[i]);

		test = 0;
		if (arr[0] + arr[5] == 7 && arr[1] + arr[3] == 7 && arr[2] + arr[4] == 7){

			test = 1;

			sort(arr, arr+6);
			for (i = 0; i < 6; i++)
				arr[i] == i+1 ? :test = 0;

		}

		if (test)
			printf("SIM\n");
		else
			printf("NAO\n");

	}

	return 0;
}
