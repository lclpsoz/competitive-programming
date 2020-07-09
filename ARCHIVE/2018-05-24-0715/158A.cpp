#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int n, k;
int arr[100];

int main ()
{
	int ans = 0, x, aux;
	scanf ("%d %d", &n, &k);
	aux = -1;
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &x);
		if (x > 0 && i <= k)
			ans++;
		else if (x > 0 && aux == x)
			ans++;
		if (i == k)
			aux = x;

	}

	printf ("%d\n", ans);

	return 0;
}
