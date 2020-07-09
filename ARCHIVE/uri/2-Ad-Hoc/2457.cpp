//Using string
#include <bits/stdc++.h>
using namespace std;

int with, total;
char a[2], str[1010];
bool test;

int main (){

	a[0] = getchar(); //Choosen
	a[1] = '\0';

	while (scanf(" %s ", str) != EOF){

		if (strstr(str, a) != NULL) with++;
		total++;

	}

	printf("%0.1lf\n", ((double)with / (double)total)*100.0);

	return 0;
}
