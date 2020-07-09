#include <bits/stdc++.h>
using namespace std;

int i;
int cents, value, arr[4];

int main (){

	while (scanf("%d %d", &value, &cents) != EOF){

		i = 0;
		while (value){

			arr[i++] = value % 1000;
			value /= 1000;

		}

		if (arr[3]){

			printf("$%d", arr[3]);
			for (i = 2; i >= 0; i--)
				printf(",%03d", arr[i]);
			printf(".%02d\n", cents);

		}
		else if (arr[2]){

			printf("$%d", arr[2]);
			for (i = 1; i >= 0; i--)
				printf(",%03d", arr[i]);
			printf(".%02d\n", cents);

		}
		else if (arr[1]){

			printf("$%d", arr[1]);
			for (i = 0; i >= 0; i--)
				printf(",%03d", arr[i]);
			printf(".%02d\n", cents);

		}
		else
			printf("$%d.%02d\n", arr[0], cents);

		for (i = 0; i < 4; i++) arr[i] = 0;

	}

	return 0;
}
