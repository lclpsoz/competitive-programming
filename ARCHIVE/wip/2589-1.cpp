#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int llu;
const llu MAXB = 1e9+100, MAXN = 200;

llu i, j, k;
llu last_prime, n;
llu mat[MAXN][5]; //Stores the biggest prime gap from that number until the next stored
bool not_prime[MAXB];

int main (){

	//Sieve of Eratosthenes adapted to the problem
	mat[0][0] = 2;
	mat[0][1] = 0;
	k = 1; //Position in mat
	last_prime = 2;
	for (i = 2; i*i <= MAXB; i++){

		if (!not_prime[i]){

			for (j = i; j < MAXB-1; j+=i){

				not_prime[j] = true;

			}

			if (i - last_prime > mat[k-1][1]){

				mat[k][0] = i;
				mat[k][1] = (i - last_prime);
				k++;

			}

			last_prime = i;

		}
	}

	/*for (i = 2; i < 1e4; i++)
		if (!not_prime[i]) printf("%d ", i);
	printf("\n");*/
	while (i < MAXB){

		if (!not_prime[i]){

			if (i - last_prime > mat[k-1][1]){

				mat[k][0] = i;
				mat[k][1] = (i - last_prime);
				k++;

			}

			last_prime = i;

		}
		i++;

	}

	//for (i = 0; i < 35; i++)
	//	printf("%d %d\n", mat[i][0], mat[i][1]);

	while (scanf("%llu", &n) != EOF){

		i = 0;
		while(i + 1 < k && mat[i + 1][0] <= n) i++;

		printf("%llu\n", mat[i][1]);

	}

	return 0;
}
