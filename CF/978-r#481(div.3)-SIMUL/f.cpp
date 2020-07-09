#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 2e5+10;

int n, k;
int a, b;
pii arr[MAXN];
int rel[MAXN];
int ans[MAXN];

int main ()
{
	scanf ("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &arr[i].x);
		arr[i].y = i;
	}
	while (k--) {
		scanf ("%d %d", &a, &b);
		if (arr[b].x < arr[a].x)
			rel[a]++;
		if (arr[a].x < arr[b].x)
			rel[b]++;
	}
	sort (arr+1, arr+n+1);
	/*for (int i = 1; i <= n; i++)
		printf ("%d ", arr[i].x);
	putchar ('\n');*/
	int igual = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i].x == arr[i-1].x)
			igual++;
		else
			igual = 0;
		ans[arr[i].y] = i-1-igual-rel[arr[i].y];
	}
	for (int i = 1; i <= n; i++)
		printf ("%d ", ans[i]);
	putchar ('\n');

	return 0;
}
