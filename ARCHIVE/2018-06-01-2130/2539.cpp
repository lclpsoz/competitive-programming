#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 1e5+10;

int n;
int arr[MAXN];
int bit[MAXN];

void add (int p, int v) {
	for (int i = p; i <= n; i+=i&-i)
		bit[i] += v;
}

int sum (int p) {
	int r = 0;
	for (int i = p; i >= 1; i-=i&-i)
		r+=bit[i];
	return r;
}

int main ()
{
	int x;
	while (scanf ("%d", &n) != EOF) {
		for (int i = n; i >= 1; i--) {
			scanf ("%d", &x);
			arr[x] = i;
			add (i, 1);
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += sum (arr[i])-1;
			add (arr[i], -1);
		}
		printf ("%lld\n", ans);
	}

	return 0;
}
