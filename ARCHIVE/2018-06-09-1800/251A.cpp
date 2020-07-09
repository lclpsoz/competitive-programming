#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 1e5+10;

int arr[MAXN];

int main ()
{
	int n, d;
	scanf ("%d %d", &n, &d);
	if (n < 3)
		printf ("0\n");
	else {
		for (int i = 0; i < n; i++)
			scanf ("%d", &arr[i]);
		int i = 0;
		int j = 2;
		ll ans = 0;
		while (j < n) {
			if (arr[j]-arr[i] > d) {
				i++;
				if (j-i < 2) j++;
			} else {
				ans += (1LL*(j-i-1)*(j-i))/2;
				j++;
			}
		}

		printf ("%lld\n", ans);
	}

	return 0;
}
