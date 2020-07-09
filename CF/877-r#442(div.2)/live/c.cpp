#include <bits/stdc++.h>
using namespace std;

int i, j;
int size, moves, pos;

int main (){

	scanf("%d", &size);

	if (size == 2){

		printf("3\n2 1 2\n");

	}
	else{

		moves = (size * 2) - 2;
		printf("%d\n", moves);

		pos = size / 2;
		for (i = 0, j = 0; i < size-2; i++){

			pos += j;
			printf("%d ", pos+1);

			if (!(i % 2)) j = (-1*j) - 1;
			else j = (-1 * j) + 1;

		}
		printf("1 %d ", size);

		for (i = 1; i < size-1; i++){

			printf("%d", i+1);
			if (i < size-2) printf(" ");

		}

		puts("");

	}

	return 0;
}
