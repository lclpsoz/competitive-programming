#include <stdio.h>
#include <math.h>

int main(){

	double A, B, C, temp;
	scanf("%lf%lf%lf", &A, &B, &C);

	if (A < B){

		temp = A;
		A = B;
		B = temp;
	
	}
	if (A < C){

		temp = A;
		A = C;
		C = temp;
	
	}
	if (B < C){

		temp = B;
		B = C;
		C = temp;
	
	}
	
	if (A >= B + C){printf("NAO FORMA TRIANGULO\n");}
	else
	{

	if (pow(A, 2) == pow(B, 2) + pow(C, 2)){printf("TRIANGULO RETANGULO\n");}
	if (pow(A, 2) > pow(B, 2) + pow(C, 2)){printf("TRIANGULO OBTUSANGULO\n");}
	if (pow(A, 2) < pow(B, 2) + pow(C, 2)){printf("TRIANGULO ACUTANGULO\n");}
	if (A == B && B == C){printf("TRIANGULO EQUILATERO\n");}
	if ((A == B && B != C) || (B == C && A != B)){printf("TRIANGULO ISOSCELES\n");}

	}
	
	return 0;
}