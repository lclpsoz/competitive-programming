#include <stdio.h>

int i, j;
int qnt, t1[3], t2[3];

int main (void){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d x %d", &t1[0], &t2[1]);

		scanf("%d x %d", &t2[0], &t1[1]);

		t1[2] = t1[0] + t1[1];
		t2[2] = t2[0] + t2[1];

		if (t1[2] == t2[2] && t1[1] == t2[1])
			printf("Penaltis\n");
		else if (t1[2] > t2[2] || (t1[2] == t2[2] && t1[1] > t2[1]))
			printf("Time 1\n");
		else if (t1[2] < t2[2] || (t1[2] == t2[2] && t1[1] < t2[1]))
			printf("Time 2\n");

		for (j = 0; j < 3; j++){

			t1[j] = 0;
			t2[j] = 0;

		}
	}

	return 0;
}
