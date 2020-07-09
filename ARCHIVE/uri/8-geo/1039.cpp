#include <bits/stdc++.h>
using namespace std;

struct _circle{

	double r;
	double x;
	double y;

} hunter, flower, dist;

int main (){

	while(scanf("%lf %lf %lf %lf %lf %lf",  &hunter.r, &hunter.x, &hunter.y, &flower.r, &flower.x, &flower.y) != EOF){

		dist.x = abs(hunter.x - flower.x);
		dist.y = abs(hunter.y - flower.y);
		dist.r = sqrt((dist.x * dist.x) + (dist.y * dist.y)); //Distance between the flower and the hunter

		if ((dist.r + flower.r) > hunter.r)
			printf("MORTO\n");
		else
			printf("RICO\n");

	}

	return 0;
}
