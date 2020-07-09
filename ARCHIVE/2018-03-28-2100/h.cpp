#include <bits/stdc++.h>
using namespace std;

int i;
int arr[3], aux, ans;

int main (){

	for (i = 0; i < 3; i++)
		scanf("%d", &arr[i]);

	ans = 0;
	for (i = 0; i < 3; i++){

		scanf("%d", &aux);
		if (aux > arr[i])
			ans += aux - arr[i];

	}

	printf("%d\n", ans);

	return 0;
}
