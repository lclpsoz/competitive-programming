#include <bits/stdc++.h>
using namespace std;

int n, arr[3], i, dist1, dist2;

int main (){

	scanf("%d %d %d %d", &n, &arr[0], &arr[1], &arr[2]);

	i = 0;
	dist1 = dist2 = 0;
	if (n == 1) printf("0\n");
	else{

		dist1 = arr[0];
		if (n > 2) dist1 += (n - 2) * min(arr[0], arr[2]);

		dist2 = arr[1];
		if (n > 2) dist2 += (n - 2) * min(arr[1], arr[2]);

		dist1 > dist2 ? printf("%d\n", dist2) : printf("%d\n", dist1);

	}

	return 0;
}
