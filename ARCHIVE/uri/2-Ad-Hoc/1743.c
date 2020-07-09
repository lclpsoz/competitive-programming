#include <stdio.h>

int i;
int arr[5], val, print;

int main (void){

	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	print = 1;
	for (i = 0; i < 5; i++){

		scanf("%d", &val);

		if (val == arr[i] && print){

			printf("N\n");
			print = 0;

		}
	}

	if (print)
		printf("Y\n");

	return 0;
}
