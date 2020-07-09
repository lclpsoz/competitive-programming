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

int arr[105];
int x, n;
int mat[105][105];
int pd[105][105];
int vals[105][105];

int func (int p, int c) {
	if (p == 0) return 0;
	if (pd[p][c] != -1)
		return pd[p][c];
	return pd[p][c] = min (func (p-1, c)+mat[p-1][c],
			func (p-1, c-1)+mat[p-1][c-1]);
}

int main ()
{
	memset (pd, -1, sizeof (pd));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf ("%d", &vals[i][j]);
			mat[i][j] = mat[i][j-1]+vals[i][j];
			if (j-i > 0)
				mat[i][j] -= vals[i][j-i];
			// printf ("%2d ", mat[i][j]);
		}
		// putchar ('\n');
	}
	cout << func (n, n)+mat[n][n] << '\n';

	return 0;
}
