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

const double EPS = 1e-6;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

typedef pair<int, pii> piii;
const int MAXN = 1e4+10;

int n, m;
priority_queue<piii, vector<piii>, greater<piii>> pq;
int size[MAXN], link[MAXN];
int bur[MAXN];
int maxi[MAXN];

int find (int a) {
	if (a == link[a]) return a;
	return link[a] = find (link[a]);
}

bool same (int a, int b) {
	return find (a) == find (b);
}

void unite (int a, int b, int w) {
	a = find (a);
	b = find (b);
	if (size[a] > size[b]) swap (a, b);
	size[b] += size[a];
	bur[b] += bur[a]+w;
	maxi[b] = max(maxi[b], maxi[a]);
	link[a] = b;
}

int main ()
{
	cin >> n >> m;
	int a, b, w;
	for (int i = 1; i <= n; i++) {
		size[i] = 1;
		link[i] = i;
		maxi[i] = i;
	}
	while (m--) {
		scanf ("%d %d %d", &a, &b, &w);
		pq.push ({w, {a, b}});
	}

	while (!pq.empty()) {
		int w = pq.top().x;
		pii p = pq.top().y;
		pq.pop();
		if (!same (p.x, p.y))
			unite (p.x, p.y, w);
	}
	double mini = INF;
	double val;
	int pos = -1;
	for (int i = 1; i <= n; i++) {
		if (size[i] == 1)
			val = 0;
		else
			val = (double)bur[i]/(size[i]-1);
		if (cmp (val, mini) <= 0) {
			pos = maxi[i];
			mini = val;
		}
	}

	cout << pos << '\n';

	return 0;
}
