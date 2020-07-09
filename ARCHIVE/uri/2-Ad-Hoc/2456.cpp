#include <bits/stdc++.h>
using namespace std;

int i;
int test, arr[6];

int main (){

	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	if (arr[0] < arr[1]){

		test = 1; //Ascending
		i = 0;
		while (++i < 4)
			if (arr[i] > arr[i+1])
				test = 0;

	}
	else if (arr[0] > arr[1]){

		test = 2; //Descending
		i = 0;
		while (++i < 4)
			if (arr[i] < arr[i+1])
				test = 0;

	}

	if (test == 1) printf("C\n");
	else if (test == 2) printf("D\n");
	else printf("N\n");

	return 0;
}
