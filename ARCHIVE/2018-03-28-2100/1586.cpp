#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n;
int arr[MAXN];
char names[MAXN][12];

// st and en are INCLUSIVE
long long group (int st, int en)
{
	int j = 1;
	long long r = 0;
	if (st > en)
		for (int i = st; i >= en; i--)
			r += arr[i]*j++;
	else
		for (int i = st; i <= en; i++)
			r += arr[i]*j++;

	return r;
}

int dif_g (int x) {
	long long d = group (x, 0)-group(x+1,n-1);
	if (!d)
		return 0;
	if (d > 0)
		return 1;
	return -1;
}

int b_bin ()
{
	int l = 0;
	int r = n-1;
	int mid;
	int d;
	while (l <= r) {
		mid = (l+r)/2;
		d = dif_g (mid);
		// printf ("%d [%d] %d → %d\n", l, mid, r, d);
		if (d < 0)
			l = mid+1;
		else if (d > 0)
			r = mid-1;
		else
			break;
	}
	if (d)
		mid = -1;

	return mid;
}

int main ()
{
	while (scanf ("%d", &n), n) {
		for (int i = 0; i < n; i++) {
			scanf ("%s", names[i]);
			arr[i] = 0;
			for (int j = 0; names[i][j] != '\0'; j++)
				arr[i] += names[i][j];
		}

		int pos = b_bin();

		if (pos == -1)
			printf ("Impossibilidade de empate.\n");
		else
			printf ("%s\n", names[pos]);
	}

	return 0;
}
