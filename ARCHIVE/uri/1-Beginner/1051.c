#include <stdio.h>

double min(double a, double b){

	if (a > b){

		return b;

	}
	else{

		return a;

	}
}

int main(){

	int i;
	double table[4][2] =
		{{2000, 0}, {3000, 8},{4500, 18}, {'\0',28}};
	double parts[3];
	double salary, tax = 0;
	scanf("%lf", &salary);

	parts[0] = min((salary - 2000), 1000);
	parts[1] = min((salary - 3000), 1500);
	parts[2] = salary - 4500;

	for (i = 0; i < 3; ++i){

		if (parts[i] > 0){

			parts[i] *= (table[i + 1][1] / 100);
			tax += parts[i];

		}
		else{

			break;
		}
	}

	if (tax > 0){

		printf("R$ %.2lf\n", tax);

	}
	else{

		printf("Isento\n");

	}

	return 0;
}
