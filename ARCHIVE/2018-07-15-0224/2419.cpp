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

int m, n;
char mp[1010][1010];
int adj[][2] = {	{0, 1},
					{1, 0},
					{0, -1},
					{-1, 0}	};

bool verif (int x, int y) {
	for (int i = 0; i < 4; i++) {
		char c = mp[x+adj[i][0]][y+adj[i][1]];
		if (c == '.' || c == '\0')
			return true;
	}
	return false;
}

int main ()
{
	scanf ("%d %d", &m, &n);
	for (int i = 1; i <= m; i++) {
		getchar ();
		for (int j = 1; j <= n; j++)
			mp[i][j] = getchar ();
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (mp[i][j] == '#' && verif (i, j))
				ans++;

	cout << ans << '\n';

	return 0;
}
