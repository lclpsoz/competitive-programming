#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll arr[505];

int main ()
{
	while (scanf ("%d", &n), n != -1) {
		n--;
		ll sum = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%lld", &arr[i]);
			sum += arr[i];
		}
		sort (arr, arr+n);

		ll x = (arr[n/2]*(n+1)) - sum;
		if (x > arr[n/2]) {
			ans++;
			for (int i = 0; i < n; i++)
				if (x == arr[i]) {
					ans--; break;
				}
		}

		x = (arr[(n/2)-1]*(n+1)) - sum;
		if (x < arr[(n/2)-1]) {
			ans++;
			for (int i = 0; i < n; i++)
				if (x == arr[i]) {
					ans--; break;
				}
		}

		if (sum%n == 0) {
			x = sum/n;
			if (x > arr[(n/2)-1] && x < arr[(n/2)]) {
				ans++;
				for (int i = 0; i < n; i++)
					if (x == arr[i]) {
						ans--; break;
					}
			}
		}
		printf ("%d\n", ans);
	}

	return 0;
}
