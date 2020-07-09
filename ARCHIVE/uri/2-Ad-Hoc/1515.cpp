#include <bits/stdc++.h>
using namespace std;

const int MAXS = 75;

int i;
int qnt, year, travel, time_m;
char str[MAXS], str_m[MAXS];

int main (){

	while (scanf("%d", &qnt), qnt){

		time_m = 3000;
		for (i = 0; i < qnt; i++){

			scanf("%s %d %d", str, &year, &travel);

			if (year - travel < time_m){

				strcpy(str_m, str);
				time_m = year - travel;

			}
		}

		printf("%s\n", str_m);

	}

	return 0;
}
