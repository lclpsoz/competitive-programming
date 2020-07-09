#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

int n, k;
int x;
int mini, maxi;
int arr[300];
int qnt[300];

int main ()
{
	memset (arr, -1, sizeof (arr));
	scanf ("%d %d", &n, &k);
	mini = maxi = -1;
	while (n--) {
		scanf ("%d", &x);
		if (arr[x] == -1) {
			int i = max (0, x-k+1);
			// printf ("\n%d: %d x %d\n", i, qnt[arr[i]], x-arr[i]+1);
			while (arr[i] != -1 && (x-arr[i]+1) > k) {
				i++;
			}
			// printf ("\n%d: %d x %d\n", i, qnt[arr[i]], x-arr[i]+1);
			mini = i;
			while (i <= x) {
				qnt[mini]++;
				arr[i] = mini;
				i++;
			}
		}
		printf ("%d ", arr[x]);
	}
	putchar ('\n');
	// printf ("%d\n", qnt[3]);

	return 0;
}
