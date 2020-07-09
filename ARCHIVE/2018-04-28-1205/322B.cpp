#include <bits/stdc++.h>
using namespace std;

int arr[3];

int main ()
{
	int x = 0;
	int mini = 1e9;
	int qnt = 0;
	for (int i = 0; i < 3; i++) {
		scanf ("%d", &arr[i]);
		x = max (x,	arr[i]%3);
		mini = min (mini, arr[i]);
		if (arr[i]%3 == 2) qnt++;
	}

	long long ans = 0;

	if (qnt >= 2 && mini >= 2)
		for (int i = 0; i < x && i < mini; i++) {
			arr[0]--;
			arr[1]--;
			arr[2]--;
			ans++;
		}
	for (int i = 0; i < 3; i++) {
		ans += arr[i]/3;
		arr[i] %= 3;
	}
	while (arr[0] && arr[1] && arr[2]) {
		ans++;
		arr[0]--;
		arr[1]--;
		arr[2]--;
	}

	printf ("%lld\n", ans);


	return 0;
}
