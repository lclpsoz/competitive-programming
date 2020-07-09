#include <stdio.h>

int i;
int guests, max, min, height, allowed;

int main (void){

	while(scanf("%d %d %d", &guests, &min, &max) != EOF){

		for (i = 0; i < guests; i++){

			scanf("%d", &height);

			if (height >= min && height <= max)
				allowed++;

		}

		printf("%d\n", allowed);
		allowed = 0;

	}

	return 0;
}
