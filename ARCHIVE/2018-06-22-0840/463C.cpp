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

const int N = 2010;

int n;
int mat[N][N];
ll esq[2*N+10];
ll dir[2*N+10];

pii pos (char c, int i, int j) {
	if (c == 'L') {
		if (i < j) {
			j-=i-1;
			i = 1;
		} else {
			i-=j-1;
			j = 1;
		}
	} else {
		int ax = n-1-j;
		return {i-ax, j+ax};
	}

	return {i, j};
}

int pos_x (char c, int i, int j) {
	pii p = pos (c, i, j);
	if (c == 'R')
		return p.x+p.y;
	return 2000+p.y-p.x;
}

int fill () {
	// LEFT
	for (int k = n-1; k >= 0; k--) {
		int p = pos_x ('L', k, 0);
		for (int i = k, j = 0; i < n; i++, j++) {
			// printf ("%d: %d %d\n", p, i, j);
			esq[p] += mat[i][j];
		}
	}
	for (int k = 1; k < n; k++) {
		int p = pos_x ('L', 0, k);
		for (int i = 0, j = k; j < n; i++, j++) {
			// printf ("%d: %d %d\n", p, i, j);
			esq[p] += mat[i][j];
		}
	}
	// RIGHT
	// printf ("|||||DIREITA|||||\n");
	for (int k = 0; k < n; k++) {
		int p = pos_x ('R', k, n-1);
		for (int i = k, j = n-1; i < n; i++, j--) {
			// printf ("%d: %d %d\n", p, i, j);
			dir[p] += mat[i][j];
		}
	}
	for (int k = 0; k < n-1; k++) {
		int p = pos_x ('R', 0, k);
		for (int i = 0, j = k; j >= 0; i++, j--) {
			// printf ("%d: %d %d\n", p, i, j);
			dir[p] += mat[i][j];
		}
	}


}

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf ("%d", &mat[i][j]);
	fill();
	/*for (int i = 0; i < 2*n; i++)
		printf ("%3d ", esq[i]);
	for (int i = 0; i < 2*n; i++)
		printf ("%3d ", dir[i]);*/
	/*for (int i = 0; i < 2*N; i++)
		if (esq[i])
			printf ("%4d ", i);
	putchar ('\n');
	for (int i = 0; i < 2*N; i++)
		if (dir[i])
			printf ("%4d ", i);
	putchar ('\n');
	// VALS
	for (int i = 0; i < 2*N; i++)
		if (esq[i])
			printf ("%4lld ", esq[i]);
	putchar ('\n');
	for (int i = 0; i < 2*N; i++)
		if (dir[i])
			printf ("%4lld ", dir[i]);
	putchar ('\n');*/

	pii p1, p2;
	ll v1, v2;
 	v1 = v2 = -10;
	for (int i = 0; i < n; i++) {
		int j;
		if (i%2 == 0)
			j = 0;
		else
			j = 1;
		for (; j < n; j+=2) {
			int l = pos_x ('L', i, j);
			int r = pos_x ('R', i, j);
			// cout << i << ' ' << j << ":\n";
			// cout << "  " << esq[l] << ' ' << dir[r] << '\n';
			if (esq[l]+dir[r]-mat[i][j] > v1) {
				v1 = esq[l]+dir[r]-mat[i][j];
				p1.x = i+1;
				p1.y = j+1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int j;
		if (i%2 == 0)
			j = 1;
		else
			j = 0;
		for (; j < n; j+=2) {
			int l = pos_x ('L', i, j);
			int r = pos_x ('R', i, j);
			if (esq[l]+dir[r]-mat[i][j] > v2) {
				v2 = esq[l]+dir[r]-mat[i][j];
				p2.x = i+1;
				p2.y = j+1;
			}
		}
	}

	// cout << v1 << '\n';
	// cout << v2 << '\n';
	printf ("%lld\n", v1+v2);
	printf ("%d %d %d %d\n", p1.x, p1.y, p2.x, p2.y);

	return 0;
}
