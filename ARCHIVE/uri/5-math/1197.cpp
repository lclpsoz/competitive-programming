#include <bits/stdc++.h>
using namespace std;

double vel, tim;
double resp;

int main (){

	while (scanf("%lf %lf", &vel, &tim) != EOF){

		resp = 0;
		if (tim)
			resp = ((vel / tim) * (4 * tim * tim)) / 2;

		printf("%.0lf\n", resp);

	}

	return 0;
}
