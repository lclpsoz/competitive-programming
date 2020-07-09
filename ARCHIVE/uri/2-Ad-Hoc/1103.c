#include <stdio.h>

int i;
int tm[5], min[3];

int main (void){

	for (i = 0; i < 4; i++){

		scanf("%d", &tm[i]);
		tm[4] += tm[i];

	}

	while (tm[4]){

		min[0] = 0;
		min[1] = tm[3] - tm[1];

		if (min[1] < 0){

			min[1] += 60;
			min[0] = 1;

		}

		min[0] = tm[2] - (tm[0] + min[0]);

		if (min[0] < 0)
			min[0] += 24;

		min[2] = min[0] * 60 + min[1];

		printf("%d\n", min[2]);

		tm[4] = 0;
		for (i = 0; i < 4; i++){

			scanf("%d", &tm[i]);
			tm[4] += tm[i];

		}
	}

	return 0;
}
