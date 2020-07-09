#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int llu;

llu prod_mat (llu mat[][2], llu mat2[][2], int mod){

	llu aux[2][2];

	aux[0][0] = ((mat[0][0]*mat2[0][0]) + (mat[0][1]*mat2[1][0])) % mod;
	aux[0][1] = ((mat[0][0]*mat2[0][1]) + (mat[0][1]*mat2[1][1])) % mod;
	aux[1][0] = ((mat[1][0]*mat2[0][0]) + (mat[1][1]*mat2[1][0])) % mod;
	aux[1][1] = ((mat[1][0]*mat2[0][1]) + (mat[1][1]*mat2[1][1])) % mod;

	mat[0][0] = aux[0][0];
	mat[0][1] = aux[0][1];
	mat[1][0] = aux[1][0];
	mat[1][1] = aux[1][1];

}

llu fib_mat (llu n, int mod){

	int i = 0;
	llu mat[2][2] = {	{1, 1},
						{1, 0}};
	llu fibs[65][2][2];//Power of 2 of fib
	llu exp = 1;

	fibs[i][0][0] = mat[0][0];
	fibs[i][0][1] = mat[0][1];
	fibs[i][1][0] = mat[1][0];
	fibs[i][1][1] = mat[1][1];
	while (exp*2 <= n){

		prod_mat(mat, mat, mod);
		fibs[++i][0][0] = mat[0][0];
		fibs[i][0][1] = mat[0][1];
		fibs[i][1][0] = mat[1][0];
		fibs[i][1][1] = mat[1][1];
		exp *= 2;

	}
	n -= exp;

	while (n){

		if ((1llu << i) > n)
			i--;
		else{

			//printf("%d %llu %llu\n", i, n, mat[0][1]);
			n -= 1llu << i;
			prod_mat(mat, fibs[i--], mod);

		}
	}

	/*for (;i >= 0; i--)
		printf("%llu ", fibs[i][0][1]);
	puts("");*/

	return mat[0][1];

}

int main (){

	llu i = 0;
	llu n;
	int mod, calls;

	while (scanf("%llu %d", &n, &mod), n || mod){

		calls = (int) (2*fib_mat(n+1, mod) - 1) % mod;
		if (calls == -1) calls = mod - 1;

		printf("Case %llu: %llu %d %d\n", ++i, n, mod, calls);// It's n+1 because in the problem it starts at fib(0), my at fib(1)

	}

	return 0;
}
