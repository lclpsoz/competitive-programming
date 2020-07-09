#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1e5+10;
int n;
int arr[MAXN];

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &arr[i]);

	int l = 0;
	int r = 1;
	int ans = 1;
	while (r < n) {
		while (arr[r] >= arr[r-1])
			r++;
		ans = max (ans, r-l);
		l = r;
		r++;
	}

	printf ("%d\n", ans);

	return 0;
}
