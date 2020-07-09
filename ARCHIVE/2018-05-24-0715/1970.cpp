#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int n, k;
int arr[105];
int cart[4];
int dp[51][51][51][101];

int solve (int a, int b, int c, int pos) {
	if (a > cart[0] || b > cart[1] || c > cart[2]) return -arr[pos-1];
	if (pos == n) return 0;
	int &dd = dp[a][b][c][pos];
	if (dd-1 > -1) return dd-1;
	int r = 0;
	r = solve (a, b, c, pos+1);
	r = max (r,
			arr[pos]+solve (a+arr[pos], b, c, pos+1));
	r = max (r,
			arr[pos]+solve (a, b+arr[pos], c, pos+1));
	r = max (r,
			arr[pos]+solve (a, b, c+arr[pos], pos+1));

	return (dd = r-1)+1;
}

int main ()
{
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf ("%d", &arr[i]);
	for (int i = 0; i < k; i++)
		scanf ("%d", &cart[i]);

	printf ("%d\n", solve (0, 0, 0, 0));

	return 0;
}
