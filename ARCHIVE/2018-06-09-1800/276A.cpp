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
	int n, k;
	int f, t;
	scanf ("%d %d", &n, &k);
	int ans = -1e9;
	while (n--) {
		scanf ("%d %d", &f, &t);
		if (t > k)
			ans = max (ans, f-t+k);
		else
			ans = max (ans, f);
	}

	printf ("%d\n", ans);

	return 0;
}
