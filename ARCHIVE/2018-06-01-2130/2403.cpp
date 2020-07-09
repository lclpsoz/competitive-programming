#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 5e4+10;

int n, m;
int a, b;
int dep[MAXN];
vector<int> adj[MAXN];
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> ans;

int main ()
{
	scanf ("%d %d", &n, &m);
	while (m--) {
		scanf ("%d %d", &a, &b);
		dep[b]++;
		adj[a].pb (b);
	}
	for (int i = 0; i < n; i++)
		if (!dep[i]) pq.push (i);

	while (!pq.empty()) {
		n--;
		int v = pq.top();
		pq.pop();
		ans.pb (v);
		for (int u : adj[v]) {
			dep[u]--;
			if (!dep[u])
				pq.push (u);
		}
	}

	if (!n)
		for (int u : ans)
			printf ("%d\n", u);
	else
		printf ("*\n");

	return 0;
}
