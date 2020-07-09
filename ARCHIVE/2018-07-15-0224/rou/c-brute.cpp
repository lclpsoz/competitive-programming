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
	for (int i = 0; i < n-2; i++)
		for (int j = i+1; j < n-1; j++) {
			int ax = a2[i]+a2[j];
			for (int k = j+1; k < n; k++)
				if (a1[i] < a1[j] && a1[j] < a1[k])
					ans = min (ans, ax+a2[k]);
		}

	printf ("%d\n", ans);


	return 0;
}
