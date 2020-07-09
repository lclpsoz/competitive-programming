#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 1e5+10;

int n;
int link[MAXN], size[MAXN];
vector<pii> vec;

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
	int v, u, c;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		size[i] = 1;
		link[i] = i;
	}
	for (int i = 1; i < n; i++) {
		scanf ("%d %d %d", &v, &u, &c);
		if (!c)
			unite (v, u);
		else
			vec.pb ({v, u});
	}

	ll ans = 0;
	for (pii p : vec) {
		ans += size[find (p.x)]*size[find (p.y)];
		unite (p.x, p.y);
	}

	printf ("%lld\n", ans);

	return 0;
}
