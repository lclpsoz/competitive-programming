#include <stdio.h>

int main(){

	double N1, N2, N3, N4, avg, exam;
	scanf("%lf%lf%lf%lf", &N1, &N2, &N3, &N4);

	avg = (N1 * 2 + N2 * 3 + N3 * 4 + N4 * 1) / 10;

	printf("Media: %0.1lf\n", avg);

	if(avg >= 7){

		printf("Aluno aprovado.\n");

	}
	else if(avg < 5){

		printf("Aluno reprovado.\n");

	}
	else if(avg >= 5 && avg < 7){

		printf("Aluno em exame.\n");
		
		scanf("%lf", &exam);
		printf("Nota do exame: %0.1lf\n", exam);

		avg = (avg + exam) / 2;

		if(avg >= 5){

			printf("Aluno aprovado.\n");

		}
		else{

			printf("Aluno reprovado.\n");

		}

		printf("Media final: %0.1lf\n", avg);

	}

	return 0;
}