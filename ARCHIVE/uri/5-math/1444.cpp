#include <bits/stdc++.h>
using namespace std;

int n, resp;

int main (){

	scanf("%d", &n);
	while (n){

		resp = 0;
		while (n > 1){

			n  = ceil((float)n / 3);
			resp += n;

		}

		printf("%d\n", resp);
		scanf("%d", &n);
	}

	return 0;
}
