#include <bits/stdc++.h>
using namespace std;

int i, j;
int arr[3], val, mini;

int main (){

	for (i = 0; i < 3; i++)
		scanf("%d", &arr[i]);

	mini = 1e7;
	for (i = 0; i < 3; i++){

		val = 0;
		for (j = 0; j < 3; j++){

			if (j != i)
				val += arr[j] * (abs(i-j) * 2);


		}
		if (val < mini)
			mini = val;

	}

	printf("%d\n", mini);

	return 0;
}
