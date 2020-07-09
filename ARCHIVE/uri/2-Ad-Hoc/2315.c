#include <stdio.h>

int i;
int date[4], days, months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main (void){

	for (i = 0; i < 4; i++)
		scanf("%d", &date[i]);

	for (i = date[1]; i < (date[3] - date[1]) + date[1]; i++){

		if (i == date[1])
			days = months[i - 1] - date[0];
		else
			days += months[i - 1];

	}

	if (date[1] == date[3])
		days += date[2] - date[0];
	else
		days += date[2];

	printf("%d\n", days);

	return 0;
}
