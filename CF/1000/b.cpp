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
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

int n, m;
int total, maxi;

int main ()
{
	cin >> n >> m;
	int bef = 0;
	int x;
	int aux = -1;
	while (n--) {
		scanf ("%d", &x);
		if (bef != -1) {
			total += x-bef;
			bef = -1;
			aux = x+1;
		} else {
			bef = x;
			if (aux != x)
				maxi = max (maxi, x-aux);
		}
		printf ("t: %d\n", total);
	}
	if (bef == -1)
		maxi = max (m-aux, maxi);
	else
		total += m-bef;

	printf ("%d\n", total+maxi);


  return 0;
}
