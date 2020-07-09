//My implementation knowing matrix exponenciation for Fibonacci to make one without matrix, at v1 using a struct of 3 values.
#include <stdio.h>

typedef long long unsigned llu;
typedef struct _trio{

	llu fut;
	llu pre;
	llu pas;

} Trio;

void cpy_trio (Trio *a, Trio *b){

	a->fut = b->fut;
	a->pre = b->pre;
	a->pas = b->pas;

}

int main (){

	int i;
	Trio fib, aux;
	Trio fib_arr[100]; //Fibs in powers of 2, to form the answer
	llu n;
	int mod;

	printf("Enter the position of the fibonacci to be printed and it's modulus\n");
	while (scanf("%llu %d", &n, &mod) != EOF){

		//Fill the array of Fibonacci values
		fib.fut = 1;
		fib.pre = 1;
		fib.pas = 0;

		i = 0;
		cpy_trio(&fib_arr[i], &fib);
		while (1llu << (i+1) <= n){

			i++;
			cpy_trio(&aux, &fib);
			fib.fut = (aux.fut*aux.fut + aux.pre*aux.pre)%mod;
			fib.pre = (aux.fut*aux.pre + aux.pre*aux.pas)%mod;
			fib.pas = (aux.pre*aux.pre + aux.pas*aux.pas)%mod;

			cpy_trio(&fib_arr[i], &fib);
			printf("2^%d = %llu -> %llu\n", i, 1llu << i,fib_arr[i].pre);

		}
		printf("\n");

		n -= 1llu << i;

		//Get the value of Fib(n)
		while (n){

			if (1llu << i > n)
				i--;
			else{

				n -= 1llu << i;
				printf("fib: %llu %llu %llu\n", fib.fut, fib.pre, fib.pas);
				cpy_trio(&aux, &fib);
				fib.fut = (aux.fut*fib_arr[i].fut + aux.pre*fib_arr[i].pre)%mod;
				fib.pre = (aux.fut*fib_arr[i].pre + aux.pre*fib_arr[i].pas)%mod;
				fib.pas = (aux.pre*fib_arr[i].pre + aux.pas*fib_arr[i].pas)%mod;
				printf("arr: %llu %llu %llu\n", fib_arr[i].fut, fib_arr[i].pre, fib_arr[i].pas);

			}
		}

		printf("Fib(%llu) %% %d = %llu\n\n", n, mod, fib.pre);

	}

	return 0;
}
