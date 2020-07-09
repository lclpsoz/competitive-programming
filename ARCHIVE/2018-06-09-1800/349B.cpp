#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int x, mini = 1e9;
int n;

int main ()
{
	scanf ("%d", &n);
	int v;
	int arr[11];
	for (int i = 1; i <= 9; i++) {
		scanf ("%d", &v);
		arr[i] = v;
		if (v <= mini) {
			mini = v;
			x = i;
		}
	}
	v = mini;
	if (v > n)
		printf ("-1");
	else if (n%v == 0) {
		// printf ("%d %d\n", n, v);
		n /= v;
		for (int i = 0; i < n; i++)
			printf ("%d", x);
	} else {
		int ax;
		int nn = v+n%v;
		n /= v;
		while (n--) {
			for (int i = 9; i >= 1; i--) {
				if (nn >= arr[i]) {
					ax = i;
					nn -= arr[i]-v;
					break;
				}
			}

			printf ("%d", ax);
		}
	}
	putchar ('\n');

	return 0;
}
