#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

int arr[1005];

int main ()
{
	int n, m;
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf ("%d", &arr[i]);
	int ans = 0;
	for (int i = 0; i < n-1; i++) {
		ans += abs (arr[i]-m);
		arr[i+1] += m-arr[i];
		arr[i] = m;
	}
	ans += abs (arr[n-1]-m);

	printf ("%d\n", ans);

	return 0;
}
