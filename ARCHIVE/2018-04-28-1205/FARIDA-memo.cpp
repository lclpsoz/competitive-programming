#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;

int n, m;
long long maxi[MAXN], x;
int arr[MAXN];

long long memo (int p)
{
	if (maxi[p] != -1)
		return maxi[p];
	else if (p == 0)
		return arr[0];
	else if (p == 1)
		return max (arr[0], arr[1]);
	else
		return maxi[p] = max (memo (p-2)+arr[p], memo(p-1));
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &m);
		for (int i = 0; i < m; i++)
			scanf ("%d", &arr[i]);

		printf ("Case %d: ", i);
		if (m == 0)
			printf ("0\n");
		else {
			for (int i = 0; i < m; i++)
				maxi[i] = -1;
			printf ("%lld\n", memo (m-1));
		}
	}

	return 0;
}
