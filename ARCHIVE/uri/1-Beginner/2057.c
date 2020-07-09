#include <stdio.h>

int depart, travel, time, sum;

int main (void){

	scanf("%d %d %d", &depart, &travel, &time);

	sum = depart + travel + time;

	if (sum > 23)
		sum -= 24;
	else if (sum < 0)
		sum += 24;

	printf("%d\n", sum);

	return 0;
}
