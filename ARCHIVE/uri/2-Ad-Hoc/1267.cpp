#include <bits/stdc++.h>
using namespace std;

int i, j;
int alumni, dinners, val;
bool test, arr[150];

int main (){

	scanf("%d %d", &alumni, &dinners);
	while (alumni || dinners){

		for (i = 0; i < alumni; i++)
			arr[i] = true;

		for (i = 0; i < dinners; i++){

			for (j = 0; j < alumni; j++){

				scanf("%d", &val);
				if (!val) arr[j] = false;

			}


		}

		test = false;
		for (i = 0; i < alumni; i++)
			if (arr[i])test = true;

		if (test) printf("yes\n");
		else puts("no");

		scanf("%d %d", &alumni, &dinners);

	}

	return 0;
}
