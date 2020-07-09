#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, m;
queue<pii> q;
unordered_map<int, bool> vis;

void ins (int x, int &d)
{
	q.push ({d+1, x});
}

int main ()
{
	scanf ("%d %d", &n, &m);
	if (n == m)
		printf("0\n");
	else {
		q.push ({0, n});
		int d, v;
		d = v = -1;
		while (!q.empty()) {
			d = q.front().first;
			v = q.front().second;
			q.pop();
			if (v == m)
				break;
			if (vis[v]) continue;
			vis[v] = true;
			ins (v*2, d);
			ins (v*3, d);
			ins (v/2, d);
			ins (v/3, d);
			ins (v+7, d);
			ins (v-7, d);
		}

		printf ("%d\n", d);
	}

	return 0;
}
