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

int n;
int opt, a, b, c, d, v;
pii arr[105];
bool adj[105][105];
bool vis[105];

void dfs (int now) {
	vis[now] = true;
	for (int i = 0; i < v; i++)
		if (adj[now][i] && !vis[i])
			dfs (i);
}

int main ()
{
	scanf ("%d", &n);
	while (n--) {
		scanf ("%d %d %d", &opt, &a, &b);
		if (opt == 1) {
			arr[v] = {a, b};
			for (int i = 0; i < v; i++) {
				c = arr[i].x;
				d = arr[i].y;
				if ((c < a && a < d) || (c < b && b < d))
					adj[v][i] = true;
				if ((a < c && c < b) || (a < d && d < b))
					adj[i][v] = true;
			}

			++v;
		} else {
			/*for (int i = 0; i < v; i++) {
				for (int j = 0; j < v; j++)
					printf ("%d ", adj[i][j]);
				putchar ('\n');
			}*/
			dfs (a-1);
			printf ("%s\n", vis[b-1] ? "YES" : "NO");
			memset (vis, 0, sizeof (vis));
		}
	}

	return 0;
}
