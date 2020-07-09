#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 1e6+10;

int n;
vector<int> adj[MAXN];
int most, acu;

int far (int v, int p, int prof) {
	int r = prof;
	for (int u : adj[v])
		if (u != p)
			r = max (r, far (u, v, prof+1));
	if (r > acu) {
		acu = r;
		most = v;
	}

	return r;
}

int func (int i) {
	printf ("%d\n", i);
	func (i+1);
	return 1;
}

int main ()
{
	int a, b;
	scanf ("%d", &n);
	while (n--) {
		scanf ("%d %d", &a, &b);
		adj[a].pb (b);
		adj[b].pb (a);
	}

	far (1, 1, 0);
	printf ("%d\n", far (most, most, 0));

	return 0;
}
