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
stack<pii> q;
ll ans;
int arr[MAXN];
int x;

int main ()
{
	while (scanf ("%d", &n), n) {
		ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &x);
			arr[i] = x;
			int pos = i;
			while (!q.empty() && x < arr[q.top().x]) {
				ans = max (ans, (i-q.top().y)*1LL*arr[q.top().x]);
				// printf (" ans: %lld\n", ans);
				ans = max (ans, (i-q.top().y+1)*1LL*x);
				// printf ("  ans: %lld\n", ans);
				// printf ("   |%d %d %d\n", i, q.top(), x);
				pos = q.top().y;
				q.pop();
			}

			q.push ({i, pos});
			// printf ("%d: %lld\n", i, ans);
		}
		if (!q.empty()) {
			x = q.top().x;
			ans = max (ans, (long long)arr[x]);
			q.pop();
		}
		while (!q.empty()) {
			ans = max (ans, (x-q.top().y+1)*1LL*arr[q.top().x]);
			q.pop();
		}

		printf ("%lld\n", ans);
	}

	return 0;
}
