#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 2e5+10;
const int MAXQ = sqrt(2e5+20);
const int MAXVL = 1e4+10;
const int MOD = 1e9+7;

int n, k, r;
int sq;
int arr[MAXN];
int sqr[MAXQ][MAXVL];
int now[MAXVL];
int vis[MAXVL];

int main ()
{
	scanf ("%d %d %d", &n, &k, &r);
	sq = sqrt (n);
	int x;
	int l, r;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		sqr[i/sq][x]++;
	}

	for (int i = 1; i <= r; i++) {
		scanf ("%d %d", &l, &r);

	}

	return 0;
}
