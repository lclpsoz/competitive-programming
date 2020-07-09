// Kruskal's
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

const int MAXN = 1010;

typedef pair<int, pii> piii;

int n, m;
int a, b, w;
priority_queue<piii, vector<piii>, greater<piii>> pq;
int size[MAXN], link[MAXN];

int find (int x) {
	while (x != link[x]) x = link[x];
	return x;
}

bool same (int x, int y) {
	return find (x) == find (y);
}

void unite (int x, int y) {
	x = find (x);
	y = find (y);
	if (size[x] > size[y]) swap (x, y);
	size[y] += size[x];
	link[x] = y;
}

int main ()
{
	for (int i = 1; i < MAXN; i++) {
		size[i] = 1;
		link[i] = i;
	}
	while (scanf ("%d %d", &n, &m) != EOF) {
		for (int i = 0; i < m; i++) {
			scanf ("%d %d %d", &a, &b, &w);
			pq.push ({w, {a, b}});
		}
		ll ans = 0;
		while (!pq.empty()) {
			piii p = pq.top();
			pq.pop();
			if (!same (p.y.x, p.y.y)) {
				unite (p.y.x, p.y.y);
				ans += p.x;
			}
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			size[i] = 1;
			if (link[i] == i) cnt++;
			link[i] = i;
		}
		if (cnt > 1)
			ans = -1;
		if (ans == -1)
			printf ("impossivel\n");
		else
			printf ("%lld\n", ans);
	}

	return 0;
}
