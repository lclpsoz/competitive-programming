#include <bits/stdc++.h>

int n, m, knights;

int main (void){

	while (scanf("%d %d", &n, &m), n && m){

		if (n == 1)
			knights = m;
		else if (m == 1)
			knights = n;
		else if (n == 2){

			if (m % 4 == 1)
				knights = (m/4)*4 + 2;
			else
				knights = ((m-1)/4)*4 + 4;

		}
		else if (m == 2){

			if (n % 4 == 1)
				knights = (n/4)*4 + 2;
			else
				knights = ((n-1)/4)*4 + 4;

		}
		else
			knights = ceil((n/2.0) * m);

		printf("%d knights may be placed on a %d row %d column board.\n", knights, n, m);

	}

}
