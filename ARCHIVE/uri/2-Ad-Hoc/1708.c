#include <stdio.h>

int pilot1, pilot2, lap;

int main (void){

	scanf("%d %d", &pilot1, &pilot2);

	lap = pilot2 / (pilot2 - pilot1);

	if (lap * pilot1 == pilot2)
		printf("%d\n", lap);
	else
		printf("%d\n", lap + 1);

	return 0;
}
