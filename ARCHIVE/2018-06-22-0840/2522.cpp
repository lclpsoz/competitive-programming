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

typedef pair<double, pii> pdi;

int n;
vector<pair<int ,pii>> v;
priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
int size[510], link[510];

int find (int a) {
	while (a != link[a]) a = link[a];
	return a;
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

double operator- (const pii &p1, const pii &p2) {
	pii p = {p1.x-p2.x, p1.y-p2.y};
	return ((double)(p.x*p.x) + (p.y*p.y));
}

double kruskal () {
	for (int i = 1; i <= n; i++) {
		size[i] = 1;
		link[i] = i;
	}
	double r = 0;
	while (!pq.empty()) {
		pdi p = pq.top();
		pq.pop();
		if (!same (p.y.x, p.y.y)) {
			unite (p.y.x, p.y.y);
			r += sqrt(p.x);
		}
	}

	return r;
}

int main ()
{
	int x, y;
	while (scanf ("%d", &n) != EOF) {
		v.clear();
		for (int i = 1; i <= n; i++) {
			scanf ("%d %d", &x, &y);
			pii p = {x, y};
			for (auto pp : v)
				pq.push ({p-pp.y, {i, pp.x}});
			v.pb ({i, {x, y}});
		}

		printf ("%.2lf\n", kruskal());
	}

	return 0;
}
