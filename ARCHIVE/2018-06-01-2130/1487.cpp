#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

int n, t;
int d, sc;
priority_queue<pair<double, pii>> pq;

int main ()
{
	int inst = 1;
	while (scanf ("%d %d", &n, &t), n || t) {
		while (n--) {
			scanf ("%d %d", &d, &sc);
			pq.push ({(double)sc/d, {d, sc}});
		}
		int ans = 0;
		while (!pq.empty() && t) {
			pii p = pq.top().y;
			pq.pop();
			while (p.x <= t) {
				ans += p.y;
				t -= p.x;
			}
		}
		while (!pq.empty()) pq.pop();

		printf ("Instancia %d\n", inst++);
		printf ("%d\n\n", ans);
	}

	return 0;
}
