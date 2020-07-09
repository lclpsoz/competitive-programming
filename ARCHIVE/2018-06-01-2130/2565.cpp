#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int main ()
{
	int n;
	double arr[111];
	double avr, ans;
	while (scanf ("%d", &n) != EOF) {
		avr = ans = 0;
		for (int i = 0; i < n; i++)
			scanf ("%lf", &arr[i]);
		sort (arr, arr+n);
		if (n%2 == 1)
			avr = arr[n/2];
		else
			avr = (arr[(n-1)/2]+arr[n/2])/2;
		for (int i = 0; i < n; i++)
			ans += abs(arr[i]-avr);
		printf ("%.2lf\n", ans);
	}

	return 0;
}
