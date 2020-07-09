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

const int MAXN = 3e3+10;

int n;
int a1[MAXN], a2[MAXN];

int main ()
{
	scanf ("%d", &n);

	for (int i = 0; i < n; i++)
		scanf ("%d", &a1[i]);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a2[i]);

	int ans = INF;
	int l = INF;
	int r = INF;
	for (int i = 1; i < n-1; i++) {
		l = r = INF;
		for (int j = 0; j < i; j++)
			if (a1[j] < a1[i])
				l = min (l, a2[j]);
		for (int j = i+1; j < n; j++)
			if (a1[i] < a1[j])
				r = min (r, a2[j]);
		ans = min (ans, l+r+a2[i]);
	}

	printf ("%d\n", ans == INF ? -1 : ans);


	return 0;
}
