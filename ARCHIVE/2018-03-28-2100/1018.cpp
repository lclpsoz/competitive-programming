#include <bits/stdc++.h>
using namespace std;

int i;
int val, notes[] = {100, 50, 20, 10, 5, 2, 1};

int main (){

	scanf("%d", &val);
	printf("%d\n", val);
	for (i = 0; i < 7; i++){

		printf("%d nota(s) de R$ %d,00\n", val / notes[i], notes[i]);
		val -= (val / notes[i])*notes[i];

	}

	return 0;
}
