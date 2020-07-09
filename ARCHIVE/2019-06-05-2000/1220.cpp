#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;

int i;
int qnt;
int arr[MAXN];
int avr, resp_flr, resp_cl;
int flr, cl;

int main (){

	scanf("%d", &qnt);
	while (qnt){
		int ans = 2000000000;
		avr = 0;
		long long acu = 0;
		for (i = 0; i < qnt; i++){
			int x, y;
			scanf ("%d.%d", &x, &y);
			arr[i] = 100*x + y;
			acu += arr[i];
		}
		
		avr = (acu/qnt);
		for (int j = 0; j < 2; j++, avr++) {
// 			printf ("%lld %lld\n", avr, acu);
			resp_flr = resp_cl = 0;
			flr = avr - 1;
			cl = avr;

			for (i = 0; i < qnt; i++){

				if (flr > arr[i])
					resp_flr += flr - arr[i];
				if (cl < arr[i])
					resp_cl += arr[i] - cl;

			}
// 			printf ("%lld: %lld %lld\n", avr, resp_cl, resp_flr);
			if (resp_cl > resp_flr) resp_flr = resp_cl;
			if (resp_flr < ans) ans = resp_flr;
		}

		printf ("$%d.%02d\n", ans/100, ans%100);

		scanf("%d", &qnt);
	}

	return 0;
}
