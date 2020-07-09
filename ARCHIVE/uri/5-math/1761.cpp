#include <bits/stdc++.h>
using namespace std;

const double PI = 3.141592654;

double angle, dist, st_height, tree_height;

int main (){

	while (scanf("%lf %lf %lf", &angle, &dist, &st_height) != EOF){

		tree_height= tan((PI / 180) * angle) * dist;
		printf("%.2lf\n", (tree_height + st_height) * 5);

	}

	return 0;
}
