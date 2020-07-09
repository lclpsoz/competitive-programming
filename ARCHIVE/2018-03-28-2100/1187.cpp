#include <bits/stdc++.h>
using namespace std;

int i, j;
double n, m, val, sum;
char opt;

int main (void){

	sum = 0;
	scanf(" %c", &opt);
	for (i = 0; i < 12; i++)
		for (j = 0; j < 12; j++){

			scanf("%lf", &val);
			if (j > i && (i+j) < 11)
				sum += val;

		}

	if (opt == 'S')
		printf("%.1lf\n", sum);
	else
		printf("%.1lf\n", sum/30);

	return 0;
}
