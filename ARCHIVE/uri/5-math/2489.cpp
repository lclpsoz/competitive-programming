#include <bits/stdc++.h>

double archer_hei, dist, archer_ang;

int main (){

	while (scanf("%lf %lf %lf", &archer_hei, &dist, &archer_ang) != EOF){

		printf("%.4lf\n", archer_hei + (tan((archer_ang - 90) * M_PI / 180) * dist));

	}

	return 0;
}
