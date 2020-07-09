#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

int n, h;
int v, t;
int ans;
priority_queue<int> pq;
vector<int> vec[1050];

int main ()
{
	while (scanf ("%d %d", &n, &h) != EOF) {
		ans = 0;
		while (n--) {
			scanf ("%d %d", &v, &t);
			vec[t].pb (v);
		}
		for (int i = h; i >= 1; i--) {
			// printf( "%d\n", i);
			for (int a : vec[i])
				pq.push (a);
			vec[i].clear ();
			if (!pq.empty()) pq.pop();
		}
		while (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}

		printf ("%d\n", ans);
	}

	return 0;
}
