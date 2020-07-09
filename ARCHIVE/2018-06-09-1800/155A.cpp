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
	int mini, maxi;
	scanf ("%d", &n);
	scanf ("%d", &mini);
	maxi = mini;
	n--;
	int ans = 0;
	int x;
	while (n--) {
		scanf ("%d", &x);
		if (x < mini) {
			mini = x;
			ans++;
		} else if (x > maxi) {
			maxi = x;
			ans++;
		}
	}

	printf ("%d\n", ans);

	return 0;
}
