#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;

int i, j;
int arr[MAXN], qnt;
bool test;

int main(){

	scanf("%d", &qnt);

	while (qnt != -1){

		for (i = 0; i < qnt; i++)
			scanf("%d", &arr[i]);

		for (i = 0; i < qnt; i++)
			if (arr[i] == i+1){

				arr[i] = 0;
				for (j = i-1; j >=0; j--)
					arr[j]++;

				i = -1;

			}

		test = true;
		for (i = 0; i < qnt; i++)
			if (arr[i])
				test = false;

		if (test)
			printf("S\n");
		else
			printf("N\n");

		scanf("%d", &qnt);
	}

	return 0;
}
