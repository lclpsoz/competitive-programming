#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 3e5+10;

int n;
int arr[MAXN];
bool check[MAXN];
int bigi, smalli;

int main ()
{
	scanf ("%d", &n);
	int x;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		if (x <= 0) {
			ans += abs (x);
			arr[0]++;
		}
		else if (x > n) {
			ans += x-n-1;
			arr[n+1]++;
		}
		else
			arr[x]++;
	}
	long long acu = arr[0];
	for (int i = 1; i <= n; i++) {
		ans += abs(acu);
		acu += arr[i]-1;
	}
	ans += abs(acu);

	printf ("%lld\n", ans);

	return 0;
}
