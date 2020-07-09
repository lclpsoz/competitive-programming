#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e6+10;

int n;
priority_queue<pii> pq;
bool verif[MAXN];

int main ()
{
	// scanf ("%d", &n);

	for (int n = 1; n <= 32; n++) {
		for (int i = 0; i < n; i++)
			verif[i] = false;
		// Starts at 0
		for (int u = 1; u < n; u++) {
			printf ("%d -> %d\n", u, 0^u);
			pq.push ({-(0^u), u});
		}
		int ans = 0;
		verif[0] = true;
		while (!pq.empty ()) {
			int w = pq.top().first;
			ans += -w;
			int v = pq.top().second;
			printf ("v(%d) -> %d\n", v, ans);
			verif[v] = true;
			for (int u = 0; u < n; u++)
				if (u != v)
					pq.push ({-(v^u), u});
			while (!pq.empty () && verif[pq.top().second])
				pq.pop();
		}
		printf ("%d: %d\n", n, ans);
	}

	return 0;
}
