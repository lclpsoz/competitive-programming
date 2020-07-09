// Until answer all distance are d^2
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef pair<int, int> point;
typedef pair<point, pii> info;

int n;
int x, y, r;
info p;
vector<info> vec;
double dist[110][110];

int operator * (point &a, point &b) {
	int _x = abs(a.x - b.x);
	int _y = abs(a.y - b.y);
	return (_x*_x)+(_y*_y);
}

pii operator - (info &a, info &b) {
	int d = a.x*b.x;
	// printf ("%d %d %d\n", d, a.y.x, b.y.x);
	pii r;
	if (d <= a.y.x)
		r.x = d;
	else
		r.x = -1;
	if (d <= b.y.x)
		r.y = d;
	else
		r.y = -1;

	return r;
}

void floyd_warshall () {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min (dist[i][j], dist[i][k]+dist[k][j]);
}

int main ()
{
	while (scanf ("%d", &n), n) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = 1e9;
		vec.clear();
		for (int i = 1; i <= n; i++) {
			scanf ("%d %d %d", &x, &y, &r);
			info p = {{x, y}, {r*r, i}};
			for (info z : vec) {
				pii d = p-z;
				// printf ("%d %d\n", d.x, d.y);
				if (d.x >= 0)
					dist[i][z.y.y] = sqrt(d.x);
				if (d.y >= 0)
					dist[z.y.y][i] = sqrt(d.y);
			}
			vec.pb (p);
		}
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] == 1000000000)
					printf (" -1 ");
				else
					printf ("%3d ", dist[i][j]);
			}
			putchar ('\n');
		}*/
		floyd_warshall ();
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] == 1000000000)
					printf (" -1 ");
				else
					printf ("%3d ", dist[i][j]);
			}
			putchar ('\n');
		}*/

		scanf ("%d", &n);
		while (n--) {
			scanf ("%d %d", &x, &y);
			if (x == y)
				printf ("0\n");
			else if (dist[x][y] == 1000000000)
				printf ("-1\n");
			else {
				printf ("%d\n", (int)dist[x][y]);
				// printf ("%.10lf\n", sqrt ((double)dist[x][y]));
			}
		}
	}

	return 0;
}
