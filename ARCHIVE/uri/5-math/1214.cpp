#include <bits/stdc++.h>
using namespace std;

int i, j;
int qnt_class, qnt_peop;
int grade, sum;
int avr;
int arr[101];
double avr_abv;

int main (){

	scanf("%d", &qnt_class);
	for (i = 0; i < qnt_class; i++){

		scanf("%d", &qnt_peop);
		for (j = 0, sum = 0; j < qnt_peop; j++){

			scanf("%d", &grade);
			sum += grade;
			arr[grade]++;

		}

		avr = (sum / qnt_peop) + 1;

		for (j = avr, avr_abv = 0; j < 101; j++)
			avr_abv += arr[j];

		printf("%.3lf%%\n", 100 * (avr_abv/qnt_peop));

		for (j = 0; j < 101; j++) arr[j] = 0;

	}

	return 0;
}
