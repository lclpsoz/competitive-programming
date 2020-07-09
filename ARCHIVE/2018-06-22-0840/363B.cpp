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

const int N = 1e6;

int n, k;
int a[N];

int main ()
{
	scanf ("%d %d", &n, &k);
	int ans = INF;
	int aux = 0;
	int p = 0;
	for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		aux += a[i];
		if (i >= k) {
			if (i-k >= 1)
				aux -= a[i-k];
			if (aux < ans) {
				p = i;
				ans = aux;
			}
		}
	}

	cout << p-k+1 << '\n';

	return 0;
}
