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

const int N = 500;

int n, c, m;
bool arr[N];

int main ()
{
	int x;
	scanf ("%d %d %d", &n, &c, &m);
	while (c--) {
		scanf ("%d", &x);
		arr[x] = true;
	}
	while (m--) {
		scanf ("%d", &x);
		arr[x] = false;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += arr[i];

	cout << ans << '\n';

	return 0;
}
