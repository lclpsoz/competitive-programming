#include <stdio.h>

int main(){

	int day[2], time[6], output[4] = {0};
	scanf("Dia %d\n%d : %d : %d\nDia %d\n%d : %d : %d",
		&day[0], &time[0], &time[1], &time[2], &day[1], &time[3], &time[4], &time[5]);

	output[3] = time[5] - time [2];
	if (output[3] < 0){

		output[2]--;
		output[3] += 60;
	
	}

	output[2] += time[4] - time [1];
	if (output[2] < 0){

		output[1]--;
		output[2] += 60;
	
	}

	output[1] += time[3] - time [0];
	if (output[1] < 0){

		output[0]--;
		output[1] += 24;
	
	}

	output[0] += day[1] - day[0];

	printf("%d dia(s)\n", output[0]);
	printf("%d hora(s)\n", output[1]);
	printf("%d minuto(s)\n", output[2]);
	printf("%d segundo(s)\n", output[3]);

	return 0;
}