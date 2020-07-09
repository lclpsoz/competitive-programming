#include <stdio.h>
#include <math.h>
#include <string.h>

//1500 is the qnt of values in fib before it cycles again (in MOD 1000)
#define MOD 1500
#define MAXS 1000100

int i, j, k;
int qnt, size;
char str[MAXS];
int fib[MOD];
int rest, resp;


int main (){

	fib[0] = 0;
	fib[1] = 1;
	for (i = 2; i < 1500; i++)
		fib[i] = (fib[i-2] + fib[i-1]) % 1000;

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%s", str);
		size = strlen(str);
		resp = 0;
		for (j = size-1, k = 0; j >= size-4 && j >= 0; j--, k++)
			resp += (str[j]-'0') * pow(10, k);
		//printf("%d\n", resp);

		//In this loop all calculation were simplified by 100, before saving it to the final answer it must be multiplied by 100
		rest = 0;
		for (j = size-5; j >= 0; j--){

			if ((str[j]-'0') % 3 == 1) rest += 10;
			else if ((str[j]-'0') % 3 == 2) rest += 5;

		}
		//printf("r: %d\n", rest);
		rest %= 15;
		rest *= 100;
		resp += rest;

		resp %= MOD;
		printf("%03d\n", fib[resp]);

	}

	return 0;

}
