#include <stdio.h>
#include <math.h>
#define G 9.80665
#define PI 3.14159

int i;
int start, end, trys;
double height, height_max, speed, angle, speed_vert, speed_hor, time, dist;

int main (void){

	while (scanf("%lf", &height) != EOF){

		scanf("%d %d", &start, &end);
		scanf("%d", &trys);

		for (i = 0; i < trys; i++){

			scanf("%lf %lf", &angle, &speed);
			angle = (angle * PI) / 180; //Converts to radians

			speed_vert = sin(angle) * speed;
			speed_hor = cos(angle) * speed;

			time += speed_vert / G;//Upwards
			height_max = height + speed_vert * time - ((G * time * time) / 2);
			time += sqrt(2 * height_max / G); 	//Downwards

			dist = speed_hor * time;

			if (dist < start || dist > end)
				printf("%.5lf -> NUCK\n", dist);
			else
				printf("%.5lf -> DUCK\n", dist);

			time = 0;

		}
	}

	return 0;
}
