#include <bits/stdc++.h>
using namespace std;

int i;
int n, val, arr[3], qnt;
char opr;
bool test[3];

int main (){

	arr[0] = arr[1] = arr[2] = -1;

	scanf("%d", &n);
	for (i = 0; i < n; i++){

		scanf(" %c %d", &opr, &val);

		if (opr == '&'){

			if (!test[0]){

				test[0] = true;
				qnt++;

			}

			if (arr[0] == -1)
				arr[0] = val;
			else{

				arr[0] &= val;

			}

		}
		else if (opr == '|'){

			if (!test[1]){

				test[1] = true;
				qnt++;

			}

			if (arr[1] == -1)
				arr[1] = val;
			else{

				arr[1] |= val;

			}



		}
		else{

			if (!test[2]){

				test[2] = true;
				qnt++;

			}

			if (arr[2] == -1)
				arr[2] = val;
			else{

				arr[2] ^= val;

			}

		}

	}

	for (i = 0; i < 3; i++){

		if (test[i] && !arr[i]){

			test[i] = false;
			qnt--;

		}

	}

	printf("%d\n", qnt);
	if (test[0])
		printf("& %d\n", arr[0]);
	if (test[1])
		printf("| %d\n", arr[1]);
	if (test[2])
		printf("^ %d\n", arr[2]);


	return 0;
}
