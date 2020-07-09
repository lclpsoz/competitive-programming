#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 1010;

int arr[MAXN];
int dp[MAXN][MAXN];



int main ()
{
	int t, n;
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf ("%d", &arr[i]);
		printf("Caso #%d: %d\n", i, func (1, n));
	}

	return 0;
}
