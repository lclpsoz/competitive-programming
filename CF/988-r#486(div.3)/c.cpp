#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int N = 2e5+10;

int k;
int n;
int arr[N];
map<int, pii> mp;

int main ()
{
	long long sum;
	scanf ("%d", &k);
	for (int i = 1; i <= k; i++) {
		scanf ("%d", &n);
		sum = 0;
		for (int j = 1; j <= n; j++) {
			scanf ("%d", &arr[j]);
			sum += arr[j];
		}
		for (int j = 1; j <= n; j++) {
			pii &p = mp[sum-arr[j]];
			if (p.x && p.x != i) {
				printf ("YES\n");
				printf ("%d %d\n", i, j);
				printf ("%d %d\n", p.x, p.y);
				return 0;
			}
			p = {i, j};
		}
	}
	printf ("NO\n");

	return 0;
}
