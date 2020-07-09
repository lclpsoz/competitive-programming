#include <bits/stdc++.h>
using namespace std;

int i;
int qnt;
int d;
int num1, num2;
int den1, den2;
int num, den;
char opr;

int mdc (int a, int b){

	if (a == 0) return b;
	return mdc(b%a, a);

}

int main (){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d / %d %c %d / %d", &num1, &den1, &opr, &num2, &den2);

		switch (opr){
			case '+':
				den = den1 * den2;
				num1 = num1 * (den / den1);
				num2 = num2 * (den / den2);
				num = num1 + num2;
				break;

			case '-':
				den = den1 * den2;
				num1 = num1 * (den / den1);
				num2 = num2 * (den / den2);
				num = num1 - num2;
				break;

			case '*':
				num = num1 * num2;
				den = den1 * den2;
				break;

			case '/':
				num = num1 * den2;
				den = den1 * num2;

		}

		d = abs(mdc(num, den));
		printf("%d/%d = %d/%d\n", num, den, num/d, den/d);

	}

	return 0;
}
