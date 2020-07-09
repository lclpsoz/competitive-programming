#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1010;

int n, w, x;
int arr[MAXN];

int main ()
{
	scanf ("%d %d", &n, &w);
	int mini = 2e9;
	int maxi = -2e9;
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &x);
		arr[i] = arr[i-1] + x;
		mini = min (mini, arr[i]);
		maxi = max (maxi, arr[i]);
	}
	// printf ("%d %d\n", mini, maxi);

	int ans = 0;
	int chao, teto;
	chao = 0;
	teto = w;
	if (mini < 0)
		chao = -mini;
	if (maxi > 0)
		teto = w-maxi;
	// printf ("%d %d\n", chao, teto);
	if (teto >= chao)
		ans = teto-chao+1;

	printf ("%d\n", ans);

	return 0;
}
