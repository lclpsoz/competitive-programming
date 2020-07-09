#include <cstdio>
#include <algorithm>

typedef long long lld;
const int MAXN = 1e6+10;

int n, i;
lld arr[MAXN], bef, now;
lld *low, val1, val2, val3;

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		val1 = 1e18;
		val2 = 1e18;
		val3 = 1e18;
		scanf ("%lld", &arr[0]);
		for (i = 1; i < n; i++) {
			scanf ("%lld", &arr[i]);
			arr[i] += arr[i-1];
		}
		i--;
		low = std::lower_bound (arr, arr+n, arr[i]/2);
		val2 = abs(arr[i]-(*low)-(*low));
		if (low > arr) {
			low--;
			val1 = abs(arr[i]-(*low)-(*low));
		}
		if ((low+2) < (arr+n)) {
			low+=2;
			val3 = abs(arr[i]-(*low)-(*low));
		}
		if (val2 < val1)
			val1 = val2;
		if (val3 < val1)
			val1 = val3;

		printf ("%lld\n", val1);
	}
	return 0;
}
