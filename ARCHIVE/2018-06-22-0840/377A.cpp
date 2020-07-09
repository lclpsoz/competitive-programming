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

const int N = 505;

int n, m, k;
int adj[][2] {	{0, 1},
				{0, -1},
				{1, 0},
				{-1, 0}	};

char mat[N][N];

void dfs (int x, int y) {
	if (k == 0) return;
	int a, b;
	mat[x][y] = '-';
	for (int i = 0; i < 4; i++) {
		a = adj[i][0];
		b = adj[i][1];
		if (mat[x+a][y+b] == '.')
			dfs (x+a, y+b);
	}
	if (k) {
		k--;
		mat[x][y] = 'X';
	} else {
		mat[x][y] = ':';
	}
}

int main ()
{
	int x, y;
	scanf ("%d %d %d ", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mat[i][j] = getchar ();
			if (mat[i][j] == '.') {
				x = i; y = j;
			}
		}
		getchar ();
	}

	dfs (x, y);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (mat[i][j] == ':')
				putchar ('.');
			else
				putchar (mat[i][j]);
		putchar ('\n');
	}
	return 0;
}
