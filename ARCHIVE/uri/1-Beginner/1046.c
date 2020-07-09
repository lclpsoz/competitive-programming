#include <stdio.h>

int main(){
	
	int st, end, dur;
	scanf("%d%d", &st, &end);

	if (end > st){

		dur = end - st;

	}
	else{

		dur = (end + 24) - st;
	}

	printf("O JOGO DUROU %d HORA(S)\n", dur);

	return 0;
}