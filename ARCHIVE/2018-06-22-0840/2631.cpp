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

const int MAXN = 1e4+10;

int n, m, q;
int link[MAXN], size[MAXN];

int find (int a) {
	int b = a;
	while (a != link[a]) a = link[a];
	return link[b] = a;
}

bool same (int a, int b) {
	return find (a) == find (b);
}

void unite (int a, int b) {
	a = find (a);
	b = find (b);
	if (size[a] > size[b]) swap (a, b);
	size[b] += size[a];
	link[a] = b;
}

int main ()
{
	int a, b;
	int t = 0;
	while (scanf ("%d %d %d", &n, &m, &q) != EOF) {
		if (t)
			putchar ('\n');
		for (int i = 1; i <= n; i++) {
			size[i] = 1;
			link[i] = i;
		}
		for (int i = 0; i < m; i++) {
			scanf ("%d %d", &a, &b);
			if (!same (a, b))
				unite (a, b);
		}
		for (int i = 0; i < q; i++) {
			scanf ("%d %d", &a, &b);
			printf ("%s\n", same (a, b) ? "S" : "N");
		}
		t++;
	}

	return 0;
}
