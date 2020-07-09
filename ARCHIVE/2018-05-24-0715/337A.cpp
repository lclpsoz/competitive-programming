#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int n, m;
int arr[110];

int main ()
{
	scanf ("%d %d", &n, &m);
	int l = 0;
	int r = n-1;
	int ans = 1e9;
	for (int i = 0; i < m; i++)
		scanf ("%d", &arr[i]);
	sort (arr, arr+m);

	do {
		ans = min (ans, arr[r]-arr[l]);
		r++; l++;
	} while (r < m);

	printf ("%d\n", ans);

	return 0;
}
