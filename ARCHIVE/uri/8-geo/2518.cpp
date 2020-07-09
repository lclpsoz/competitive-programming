#include <bits/stdc++.h>
using namespace std;

double steps, height, lengh, width, hyp;

int main (){

	while (scanf("%lf %lf %lf %lf", &steps, &height, &lengh, &width) != EOF){

		hyp = sqrt(pow(height, 2) + pow(lengh, 2));
		printf("%.*lf\n", 4, (hyp * width * steps) / 1e4);

	}

	return 0;
}
