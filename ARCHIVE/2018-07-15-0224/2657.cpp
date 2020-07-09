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

const int N = 1e4+10;

int n, m, q;
int lvl;
char s1[11], s2[11];
bool valid[N];
int levels[N];
map<string, int> id;
int maxi[N], link[N], size[N];

int find (int a) {
	while (a != link[a]) a = link[a];
	return a;
}

bool same (int a, int b) {
	return find (a) == find (b);
}

void unite (int a, int b) {
	// cout << a << " + " << b << '\n';
	a = find (a);
	b = find (b);
	if (size[a] > size[b]) swap (a, b);
	size[b] += size[a];
	maxi[b] = max (maxi[b], maxi[a]);
	link[a] = b;
}

int main ()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		size[i] = 1;
		link[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf ("%s %d", s1, &lvl);
		// cout << i << ": " << s1 << ' ' << lvl << '\n';
		if (lvl >= 5)
			valid[i] = true;
		id[s1] = i;
		levels[i] = lvl;
		maxi[i] = lvl;
	}
	while (m--) {
		scanf ("%s %s", s1, s2);
		int a, b;
		a = id[s1];
		b = id[s2];
		// cout << s1 << " " << s2 << '\n';
		// cout << a << '|' << b << '\n';
		if (!same (a, b))
			unite (a, b);
	}
	for (int i = 1; i <= n; i++)
		if (!valid[i]) {
			// cout << i << '\n';
			// printf ("  %d\n", maxi[find(i)]);
			if (link[i] == i && size[i] == 1)
				valid[i] = true;
			else if (maxi[find(i)] <= 5)
				valid[i] = true;
		}
	while (q--) {
		scanf ("%s", s1);
		printf ("%s\n", valid[id[s1]] ? "S" : "N");
	}


	return 0;
}
