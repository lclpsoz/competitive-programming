#include <bits/stdc++.h>
using namespace std;

int i;
int numb;

int main (){

	scanf("%d", &numb);

	while (numb != -1){

		printf("Experiment %d: %d full cycle(s)\n", ++i, numb/2);
		scanf("%d", &numb);

	}

	return 0;
}
