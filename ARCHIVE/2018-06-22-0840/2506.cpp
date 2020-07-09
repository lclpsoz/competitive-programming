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

vector<int> arr[24*60];

int main ()
{
	int n;
	int h, m, c;
	while (scanf ("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf ("%d %d %d", &h, &m, &c);
			m += h*60;
			c += m;
			arr[m].pb (c);
		}
		queue<int> q;
		int ans = 0;
		for (int i = 7*60; i <= 21*60; i++) {
			for (int u : arr[i])
				q.push (u);
			arr[i].clear();
			if (i%30 == 0 && !q.empty()) {
				if (q.front() < i)
					ans++;
				// printf ("|[%d] %d\n", q.front(), ans);
				q.pop();
			}
		}
		while (!q.empty()) {
			q.pop();
			ans++;
		}

		printf ("%d\n", ans);
	}

	return 0;
}

