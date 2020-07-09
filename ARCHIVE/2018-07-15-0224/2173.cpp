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

typedef pair<int, pii> piii;

const int MAXN = 1e4+10;
const int MAXM = 1e5+10;

int n, m;
piii vec[MAXM];
int size[MAXN], link[MAXN];

int find (int a) {
	if (a == link[a]) return a;
	return link[a] = find (link[a]);
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

void zerar() {
	for (int i = 1; i <= n; i++) {
		size[i] = 1;
		link[i] = i;
	}
}
int main ()
{
	int x, y, c;
	while (scanf ("%d %d", &n, &m), n || m) {
		for (int i = 0; i < m; i++) {
			scanf ("%d %d %d", &x, &y, &c);
			vec[i] = {c, {x, y}};
		}
		sort (vec, vec+m);
		zerar();
		int mini = 0;
		for (int i = 0; i < m; i++) {
			int &w = vec[i].x;
			int &a = vec[i].y.x;
			int &b = vec[i].y.y;
			if (!same (a, b)) {
				mini += w;
				unite (a, b);
			}
		}
		zerar();
		int maxi = 0;
		for (int i = m-1; i >= 0; i--) {
			int &w = vec[i].x;
			int &a = vec[i].y.x;
			int &b = vec[i].y.y;
			if (!same (a, b)) {
				maxi += w;
				unite (a, b);
			}
		}

		cout << maxi - mini << '\n';
	}


	return 0;
}
