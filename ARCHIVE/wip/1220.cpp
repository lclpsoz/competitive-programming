#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;

int i;
int qnt;
double arr[MAXN], avr, resp;
int flr, cl;

int main (){

	scanf("%d", &qnt);
	while (qnt){

		resp = 0;
		avr = 0;
		for (i = 0; i < qnt; i++){

			scanf("%lf", &arr[i]);
			avr += arr[i];

		}
		avr /= qnt;
		flr = floor(avr);
		cl = ceil(avr);

		sort(arr, arr + qnt);

		for (i = 0; i < qnt; i++){

			if (avr - arr[i] >= 0.005)
				resp += avr - arr[i];

		}

		resp = floor(resp*100)/100;

		printf("$%.2lf\n",  resp);

		scanf("%d", &qnt);
	}

	return 0;
}
