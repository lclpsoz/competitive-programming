#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e5+10;
const int INF = 2e9;

int n;
int arr[MAXN];

int solve (int pos, int r) {
	// printf ("%d %d\n", pos, r);
	if (arr[pos-1] < 0) return INF;
	if (pos == n) return 0;
	int ret = INF;
	// printf ("|%d %d\n", arr[pos], arr[pos-1]+r);
	if (arr[pos] == (arr[pos-1]+r)) {
		// printf ("<<\n");
		ret = solve (pos+1, r);
	}
	if (ret != INF) return ret;
	// printf ("---\n");

	arr[pos]--;
	if (arr[pos] == arr[pos-1]+r)
		ret = 1 + solve (pos+1, r);
	arr[pos]++;
	if (ret != INF) return ret;

	arr[pos]++;
	if (arr[pos] == arr[pos-1]+r)
		ret = 1 + solve (pos+1, r);
	arr[pos]--;
	return ret;
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &arr[i]);
	if (n < 3)
		printf ("0\n");
	else {
		int a, b, ans = INF;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				a = i-1;
				b = j-1;
				arr[0] += a;
				arr[1] += b;
				// printf ("||%d %d\n", arr[0], arr[1]);
				int aux = solve (2,
							((arr[1]) - (arr[0])));
				if (i != 1)
					aux++;
				if (j != 1)
					aux++;
				ans = min (aux, ans);
				arr[0] -= a;
				arr[1] -= b;
				// printf ("ans: %d\n", ans);
			}

		printf ("%d\n", ans == INF ? -1 : ans);
	}

	return 0;
}
