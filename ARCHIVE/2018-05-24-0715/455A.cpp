#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1e5+10;

int n;
int x;
long long arr[MAXN];
long long dp[MAXN];

long long func (int pos)
{
	if (pos >= (MAXN-8)) return 0;
	if (dp[pos] > -1) return dp[pos];
	return dp[pos] = max ((pos+2)*arr[pos+2]+func(pos+2), (pos+3)*arr[pos+3]+func(pos+3));
}

int main ()
{
	memset (dp, -1, sizeof(dp));
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		arr[x]++;
	}

	printf ("%lld\n", max (arr[0]+func (0), arr[1]+func (1)));

	return 0;
}
