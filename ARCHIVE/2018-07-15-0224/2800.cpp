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

const int MAXN = 1e5+10;
const int MAXQ = sqrt(1e5+10)+2;

int n, q;
int arr[MAXN], arr_sq[MAXQ][MAXN];

int main ()
{
	scanf ("%d %d", &n, &q);
	int sq = sqrt (n), opt, x, y, w;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &arr[i]);
		arr_sq[i/sq][arr[i]]++;
	}
	while (q--) {
		scanf ("%d", &opt);
		if (opt == 1) {
			scanf ("%d %d", &x, &w);
			--x;
			arr_sq[x/sq][arr[x]]--;
			arr[x] = w;
			arr_sq[x/sq][w]++;
		} else {
			scanf ("%d %d %d", &x, &y, &w);
			--x; --y;
			int total = y-x+1;
			int cont = 0;
			for (; x <= y && x%sq; x++)
				cont += (arr[x] == w);
			for (; (x+sq-1) <= y; x+=sq)
				cont += arr_sq[x/sq][w];
			for (; x <= y; x++)
				cont += (arr[x] == w);
			printf ("%d\n", total-cont);
		}
	}


  return 0;
}
