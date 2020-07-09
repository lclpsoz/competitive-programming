#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1e5+10;

int n, k;
int arr[MAXN];

int main ()
{
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf ("%d", &arr[i]);
	sort (arr, arr+n);

	int l, r;
	l = 0;
	r = n-k-1;
	int ans = arr[r]-arr[l];
	for (int i = r; r < n; l++, r++)
		ans = min (arr[r]-arr[l], ans);

	printf ("%d\n", ans);


	return 0;
}
