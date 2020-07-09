#include <bits/stdc++.h>
using namespace std;

int n;
int t, c;
vector<int> proc[1010];
priority_queue <int, vector<int>, greater<int>> pq;
int ans; // time waiting

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		for (int i = 0; i < 1010; i++)
			proc[i].clear ();
		ans = 0;
		int last = 0;
		while (n--) {
			scanf ("%d %d", &t, &c);
			proc[t].push_back (c);
			last = max (last, t);
		}
		bool used = false;
		int fin = 1;
		for (int i = 1; i <= last; i++) {
			// Finished process
			if (fin == i)
				used = false;
			for (int x : proc[i])
				pq.push (x);
			if (!used && !pq.empty ()) {
				used = true;
				fin = i+pq.top();
				pq.pop();
			}
			ans += pq.size ();
			printf ("|%d\n", ans);
		}
		if (fin > last)
			ans += (fin-last)*((int)pq.size());
		printf (":%d\n", ans);
		while (pq.size() > 1) {
			ans += pq.size() * pq.top();
			printf (":%d\n", ans);
			pq.pop();
		}
		while (!pq.empty ())
			pq.pop();
		printf ("%d\n", ans);
	}

	return 0;
}
