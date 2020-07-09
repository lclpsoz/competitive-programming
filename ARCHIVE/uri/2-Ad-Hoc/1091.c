#include <stdio.h>

typedef struct coord_s{

	int x;
	int y;

} Coord;

int i;
int runs;
Coord div, test;

int main (void){

	scanf("%d", &runs);
	while (runs != 0){

		scanf("%d %d", &div.x, &div.y);

		for (i = 0; i < runs; i++){

			scanf("%d %d", &test.x, &test.y);

			if (test.x == div.x || test.y == div.y)
				printf("divisa\n");
			else if (test.x > div.x){

				if (test.y > div.y)
					printf("NE\n");
				else
					printf("SE\n");

			}
			else{

				if (test.y > div.y)
					printf("NO\n");
				else
					printf("SO\n");

			}
		}
		scanf("%d", &runs);

	}

	return 0;
}

