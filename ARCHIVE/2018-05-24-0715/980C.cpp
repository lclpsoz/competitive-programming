#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1e5+10;

int n, k;
int x;
int arr[300];

int main ()
{
	memset (arr, -1, sizeof (arr));
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		if (arr[x] == -1) {
			int val = max (0, x-k+1);
			// printf ("(%d)\n", val);
			while (arr[val] >= 0)
				val++;
			for (int j = val; j <= x; j++)
				arr[j] = val;
		}
		printf ("%d ", arr[x]);
	}
	putchar('\n');


	return 0;
}
