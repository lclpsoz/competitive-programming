// Kruskal
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

int n, m;
priority_queue<piii, vector<piii>, greater<piii>> pq;
vector<piii> ans;
int link[110];
int size[110];

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

int main ()
{
	int cot = 1;
	int a, b, w;
	while (scanf ("%d %d", &n, &m), n) {
		ans.clear();
		for (int i = 1; i <= n; i++) {
			link[i] = i;
			size[i] = 1;
		}
		while (m--) {
			scanf ("%d %d %d", &a, &b, &w);
			pq.push ({w, {a, b}});
		}
		while (!pq.empty()) {
			int w = pq.top().x;
			pii ar = pq.top().y;
			// cout << ": " << ar.x << ' ' << ar.y << '\n';
			pq.pop();
			if (same (ar.x, ar.y)) continue;
			ans.pb ({w, ar});
			unite (ar.x, ar.y);
		}

		sort (ans.begin(), ans.end());
		printf ("Teste %d\n", cot++);
		for (piii p : ans) {
			if (p.y.x > p.y.y) swap (p.y.x, p.y.y);
			printf ("%d %d\n", p.y.x, p.y.y);
		}
		putchar ('\n');

	}

	return 0;
}
