#include <stdio.h>

int main(){

	int i;
	int qnt, avrg;
	scanf("%d", &qnt);
	float values[qnt][3];

	for (i = 0; i < qnt; i++)
		scanf("%f %f %f", &values[i][0], &values[i][1], &values[i][2]);

	for (i = 0; i < qnt; i++)
		printf("%0.1f\n", (2 * values[i][0] + 3 * values[i][1] + 5 * values[i][2])/10);

	return 0;
}
