//Brute force for the 1226 logic
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;

int i;
int n, ans, aux;
bool test;

int main (){

	//printf("Input: ");
	while (scanf("%d", &n) != EOF){

		ans = 0;
		for (i = 4; i <= n; i++){

			aux = i;
			test = false;
			while (aux > 0 && !test){

				if (!((aux - 4) % 10) || !((aux - 13) % 100)) test = true;
				aux /= 10;

			}

			if (test){

				//printf("%d\n", i);
				ans++;

			}


		}
		printf("%d\n", ans);
		//printf("Input: ");

	}

	return 0;
}
