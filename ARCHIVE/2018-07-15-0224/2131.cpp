#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 105;

int n, m;
int arr[MAXN];
vector<int> adj[MAXN];

bool dfs (int v, int p, int cor) {

	if (arr[v] == cor) return true;
	else if (arr[v] != 2) return false;
	arr[v] = cor;
	for (int u : adj[v])
		if (u != p)
			if (!dfs (u, v, !cor))
				return false;
	return true;
}


int main ()
{
	int a, b;
	int ins = 0;
	while (scanf ("%d %d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++) {
			arr[i] = 2;
			adj[i].clear();
		}
		while (m--) {
			scanf ("%d %d", &a, &b);
			adj[a].pb (b);
			adj[b].pb (a);
		}
		printf ("Instancia %d\n", ++ins);
		printf ("%s\n\n", dfs (1, 1, 1) ? "sim" : "nao");
	}

	return 0;
}
