#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int main ()
{
	int n;
	int arr[1010];
	while (scanf ("%d", &n) != EOF) {
		for (int i = 0; i < n; i++)
			scanf ("%d", &arr[i]);
		sort (arr, arr+n);

		printf ("%d %d\n", n/2, arr[n/2]-arr[(n-1)/2]);
	}

	return 0;
}
