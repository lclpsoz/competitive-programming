#include <bits/stdc++.h>
using namespace std;

double d, vf, vg, d_g;

int main (){

	while(scanf("%lf %lf %lf", &d, &vf, &vg) != EOF){

		d_g = sqrt((12*12) + (d*d));

		if (12/vf < d_g/vg)
			printf("N\n");
		else
			printf("S\n");

	}

	return 0;
}
