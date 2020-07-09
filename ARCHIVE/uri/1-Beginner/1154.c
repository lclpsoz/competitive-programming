#include <stdio.h>

float avr;
int age, age_total, qnt;

int main (void){

	scanf("%d", &age);

	while (age > 0){

		qnt++;

		age_total += age;

		scanf("%d", &age);
	
	}

	printf("%.2f\n", (float) age_total / qnt);

	return 0;

}
