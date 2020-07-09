#include <stdio.h>
#include <math.h>

int f_x, f_y, i_x, i_y, speed, rad1, rad2;
double dist;

int main (void){

	while (scanf("%d %d %d %d %d %d %d", &f_x, &f_y, &i_x, &i_y, &speed, &rad1, &rad2) != EOF){

		dist = sqrt(pow((f_x - i_x), 2) + pow((f_y - i_y), 2));
		dist += speed * 1.5;

		if (dist > (rad1 + rad2))
			printf("N\n");
		else
			printf("Y\n");

	}

	return 0;
}
