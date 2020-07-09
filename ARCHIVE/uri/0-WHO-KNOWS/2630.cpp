#include <bits/stdc++.h>
using namespace std;

int i, j;
double qnt, val, maxi, mini, mean, eye;
char opt[10];

int main (){

	scanf("%lf", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%s", opt);
		maxi = -1;
		mini = 300;
		mean = eye = 0;
		for (j = 0; j < 3; j++){

			scanf("%lf", &val);

			maxi = max(val, maxi);
			mini = min(val, mini);
			mean += val;
			switch (j){
				case 0: eye += 0.3 * val; break;
				case 1: eye += 0.59 * val; break;
				case 2: eye += 0.11 * val; break;
			}
		}

		mean /= 3.0;

		if (opt[1] == 'a') printf("Caso #%d: %d\n", i+1, (int)maxi);
		else if (opt[1] == 'i') printf("Caso #%d: %d\n", i+1, (int)mini);
		else if (opt[1] == 'e') printf("Caso #%d: %d\n", i+1, (int)mean);
		else if (opt[1] == 'y') printf("Caso #%d: %d\n", i+1, (int)eye);

	}

	return 0;
}
