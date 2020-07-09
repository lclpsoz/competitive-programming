#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int n, x;
char arr1[MAXN], arr2[MAXN];
long long ans;

int main ()
{
	scanf ("%d", &n);
	while (n--) {
		ans = 0;
		scanf ("%s %s", arr1, arr2);
		for (int i = 0; arr1[i] != '\0'; i++) {
			x = arr2[i]-arr1[i];
			if (x < 0)
				x += 'z'-'a'+1;
			ans += x;
		}
		printf ("%lld\n", ans);

	}

	return 0;
}
