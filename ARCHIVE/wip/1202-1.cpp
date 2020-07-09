//Using matriz to get the fib value
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+100;

int qnt, size;
char str[MAXN];
int resp[2][2] = {	{1, 1},
					{1, 0}};
int fib[2][2] = {	{1, 1},
					{1, 0}};

//Function that multiplies two 2x2 matrixs and saves the result in the mat_a
void mat_mult(int mat_a[][2], int mat_b[][2]){

	int i, j;
	int mat_aux[2][2];

	mat_aux[0][0] = (mat_a[0][0] * mat_b[0][0]) + (mat_a[0][1] * mat_b[1][0]);
	mat_aux[0][1] = (mat_a[0][0] * mat_b[0][1]) + (mat_a[0][1] * mat_b[1][1]);
	mat_aux[1][0] = (mat_a[1][0] * mat_b[0][0]) + (mat_a[1][1] * mat_b[1][0]);
	mat_aux[1][1] = (mat_a[1][0] * mat_b[0][1]) + (mat_a[1][1] * mat_b[1][1]);
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			mat_a[i][j] = mat_aux[i][j] % 1000;

}

int main (){

	int i, j, k;
	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%s", str);
		size = strlen(str);

		if (!(str[size-1]-'0')) resp[0][0] = 0; //Marks with a 0 if the value in the position 0 is 0

		//Starts from size-2 because the first position in the binary number is n*2^0
		for (j = size-2; j >= 0; j--){

			//printf("j(%d)\n", j);
			//printf("%d\n\n", resp[0][0]);
			mat_mult(fib, fib);
			if (str[j]-'0'){
				//If the first position is 0, then resp will start with the values of the first "position" with 1, that way, will be equal to fib in that position
				if (!resp[0][0]){

					resp[0][0] = fib[0][0];
					resp[0][1] = fib[0][1];
					resp[1][0] = fib[1][0];
					resp[1][1] = fib[1][1];

				}
				else
					mat_mult(resp, fib);

			}


		}

		printf("%03d\n", resp[0][1]);

		resp[0][0] = fib[0][0] = 1;
		resp[0][1] = fib[0][1] = 1;
		resp[1][0] = fib[1][0] = 1;
		resp[1][1] = fib[1][1] = 0;

	}

	return 0;
}
