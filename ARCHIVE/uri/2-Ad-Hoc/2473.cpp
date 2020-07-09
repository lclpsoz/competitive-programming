#include <bits/stdc++.h>
using namespace std;

int i;
int arr[101];
int val, ans;

int main (){

	for (i = 0; i < 6; i++){

		scanf("%d", &val);
		arr[val]++;

	}

	for (i = 0; i < 6; i++){

		scanf("%d", &val);
		if (arr[val]) ans++;

	}
	switch (ans){

		case 6:
			printf("sena\n");
			break;
		case 5:
			printf("quina\n");
			break;
		case 4:
			printf("quadra\n");
			break;
		case 3:
			printf("terno\n");
			break;
		default:
			printf("azar\n");
			break;

	}

	return 0;
}
