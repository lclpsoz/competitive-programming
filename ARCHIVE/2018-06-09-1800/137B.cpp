#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

bool arr[5010];

int main ()
{
	int n, x;
	scanf ("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		if (x > n || arr[x]) ans++;
		arr[x] = true;
	}

	printf ("%d\n", ans);

	return 0;
}
