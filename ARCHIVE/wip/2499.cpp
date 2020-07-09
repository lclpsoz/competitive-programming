#include <bits/stdc++.h>
using namespace std;

long long unsigned area_ori, n, m;
long long unsigned coord_1, coord_2, coord_3;
long long unsigned area_sub;

int main (){

	scanf("%llu %llu %llu", &area_ori, &n, &m);

	while (area_ori || n || m){

		scanf("%llu %llu %llu", &coord_1, &coord_2, &coord_3);
		area_sub = (coord_1 * (coord_3 - coord_2) * area_ori) / ((n+1) * (m+1));

		printf("%llu\n", area_sub);

		scanf("%llu %llu %llu", &area_ori, &n, &m);
	}

	return 0;
}
