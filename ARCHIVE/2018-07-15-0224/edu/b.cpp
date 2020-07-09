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

const int MAXN = 1e7+20;

int n, k;
int arr[MAXN];
int bit[MAXN];

void add (int p, int v) {
	while (p < MAXN) {
		bit[p]++;
		p+=p&-p;
	}
}

int sum (int p) {
	int r = 0;
	while (p >= 1) {
		r += bit[p];
		p-=p&-p;
	}

	return r;
}

int main ()
{
	scanf ("%d %d", &n, &k);
	int x;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		add (x, 1);
		arr[x]++;
	}

	for (int i = 1; i < MAXN; i++)
		if (arr[i])
			if (sum (i+k)-sum(i))
				n -= arr[i];

	printf ("%d\n", n);

	return 0;
}
