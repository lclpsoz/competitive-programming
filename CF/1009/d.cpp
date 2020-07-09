#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
#define len(x) (int)x.size()
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 1e5+10;

int n, m;
vector<pii> v;
set<int> s[MAXN];

bool inter (int i, int j) {
	if (s[i].empty() || s[j].empty())
		return false;
	for (int v : s[i])
		if (s[j].count(v))
			return true;
	return false;
}

int main ()
{
	cin >> n >> m;
	if (n == 1 && m == 0)
		printf ("Possible\n");
	else if (n == 1 || m < n-1)
		printf ("Impossible\n");
	else {
		for (int i = 2; i <= n; i++)
			v.pb ({1, i});
		for (int i = 2; v.size() < m && i <= n; i++)
			for (int j = i+1; v.size() < m && j <= n; ++j) {
				// printf ("%d %d %d %d\n", i, j, s[i].empty(), j%i);
				if (s[i].empty() && j%i == 0)
					s[j].insert (i);
				else if (!inter (i, j))
					v.pb ({i, j});
			}
		if (v.size() == m) {
			printf ("Possible\n");
			for (pii x : v)
				printf ("%d %d\n", x.x, x.y);
		}
		else
			printf ("Impossible\n");
	}

  return 0;
}
