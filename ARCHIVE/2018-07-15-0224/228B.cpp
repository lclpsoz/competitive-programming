#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
#define len(x) (int)x.size()
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

char a[52][52];
char b[52][52];
int ans = -INF;
int n1, n2, m1, m2;
pii shift;

void check () {
	int n3 = max (n1, n2);
	int m3 = max (m1, m2);
	for (int x = 0; x < n3; x++)
		for (int y = 0; y < m3; y++) {
			int aux = 0;
			printf ("x, y: %d %d\n", x, y);
			printf ("%d %d\n", n1, n2);
			for (int i = 0; i < n1 && i+x < n2; i++) {
				for (int j = 0; j < m1 && j+y < m2; j++) {
					printf ("(i, j): %d %d\n", i, j);
					if (a[i][j] == '1' && b[i+x][j+y] == '0') {
						++aux;
						printf ("%d %d %d %d\n", i, j, i+x, j+y);
					}
				}
			}
			printf ("aux: %d\n", aux);
			if (aux > ans) {
				shift = {x, y};
				ans = aux;
			}
		}
}

int main ()
{
	scanf ("%d %d", &n1, &m1);
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < m1; j++)
			scanf (" %c", &a[i][j]);
	scanf ("%d %d", &n2, &m2);
	for (int i = 0; i < n2; i++)
		for (int j = 0; j < m2; j++)
			scanf ("%d", &b[i][j]);
	check ();
	printf ("%d %d\n", shift.x, shift.y);

  return 0;
}
