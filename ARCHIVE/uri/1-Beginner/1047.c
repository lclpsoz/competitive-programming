#include <stdio.h>

int main(){
	
	int st_hr, st_min, end_hr, end_min, dur_hr, dur_min;
	scanf("%d%d%d%d", &st_hr, &st_min, &end_hr, &end_min);

	if (end_hr > st_hr){

		dur_hr = end_hr - st_hr;

	}
	else if (end_hr <= st_hr){

		dur_hr = (end_hr + 24) - st_hr;

	}

	dur_min = end_min - st_min;

	if (dur_min < 0){

		dur_hr--;
		dur_min += 60;

	}

	printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", dur_hr, dur_min);

	return 0;
}