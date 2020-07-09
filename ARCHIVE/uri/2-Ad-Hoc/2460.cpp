#include <bits/stdc++.h>
using namespace std;

int i;
int qnta, qntb, val;
bool arr[50010], test;
queue<int> people;

int main (){

	scanf("%d", &qnta);
	for (i = 0; i < qnta; i++){

		scanf("%d", &val);
		people.push(val);

	}

	scanf("%d", &qntb);
	for (i = 0; i < qntb; i++){

		scanf("%d", &val);
		arr[val] = true;

	}

	for (i = 0; i < qnta; i++){

		val = people.front();
		people.pop();
		if (!arr[val]){

			if (test)
				printf(" ");
			printf("%d", val);
			test = true;

		}

	}
	printf("\n");


	return 0;
}
