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

int n, m;

int main ()
{
	scanf ("%d %d", &n, &m);
	int x;
	vector<int> v;
	while (m--) {
		scanf ("%d", &x);
		v.pb (x);
	}
	int pos = 1;
	ll ans = 0;
	for (int p : v)
		if (p > pos) {
			ans += p-pos;
			pos = p;
		} else if (p < pos) {
			ans += n-pos+p;
			pos = p;
		}

	cout << ans << '\n';

	return 0;
}
