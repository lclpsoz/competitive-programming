#include <stdio.h>

typedef struct coord{

	int x;
	int y;

}Coord;

int i, j;
int qnt;
Coord a, b, c, d, robot;

int main (void){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d %d", &a.x, &a.y);
		scanf("%d %d", &b.x, &b.y);
		scanf("%d %d", &c.x, &c.y);
		scanf("%d %d", &d.x, &d.y);
		scanf("%d %d", &robot.x, &robot.y);

		if (robot.x >= a.x && robot.x <= b.x && robot.y >= a.y && robot.y <= c.y)
			printf("1\n");
		else
			printf("0\n");

	}

	return 0;
}
