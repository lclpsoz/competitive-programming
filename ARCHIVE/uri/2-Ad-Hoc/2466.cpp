#include <bits/stdc++.h>
using namespace std;

const int MAXN = 70;

int i, j;
int qnt, val;
int arr[MAXN]; //1 is black, -1 is white

int main (){

	scanf("%d", &qnt);
	scanf("%d", &val);
	arr[0] = val;
	for (i = 1; i < qnt; i++){

		scanf("%d", &val);
		for (j = 1; j <= i; j++){

			if (arr[j-1] != val){

				arr[j-1] = val;
				val = -1;

			}
			else{

				arr[j-1] = val;
				val = 1;

			}
		}
		arr[j-1] = val;
		/*for (j = 0; j < qnt; j++)
			printf("%3d", arr[j]);
		printf("\n");*/

	}

	if (val == 1) printf("preta\n");
	else printf("branca\n");

	return 0;
}
