#include <stdio.h>
#include <math.h>

int i;
int tp; //tp: -1 the expoent is negative, 1 the expoent is positive
double num, num_abs;
char str[120];

int main (void){

	scanf("%s", str);
	sscanf(str, "%lf", &num);
	//printf("%lf", num);
	//scanf("%lf", &num);
	if (num == 0.0 && str[0] == '-')
		printf("-0.0000E+00\n");
	else if(num == 0.0)
		printf("+0.0000E+00\n");
	else{
		num_abs = fabs(num);

		if (num > 0)
			printf("+");
		else
			printf("-");

		if (num_abs >= 1)
			tp = 1;
		else
			tp = -1;

		while (num_abs >= 10){

			num_abs /= 10;
			i++;

		}

		while (num_abs < 1){

			num_abs *= 10;
			i++;

		}

		if (tp == 1)
			printf("%0.4lfE+%02d\n", num_abs, i);
		else
			printf("%0.4lfE-%02d\n", num_abs, i);
	}

	return 0;
}
