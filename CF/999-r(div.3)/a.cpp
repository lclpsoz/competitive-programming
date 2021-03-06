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

deque<int> dq;

int main ()
{
	int n, k;
	int a;
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a);
		dq.pb (a);
	}
	int ans = 0;
	while (!dq.empty()) {
		if (dq.front() <= k) {
			dq.pop_front();
			ans++;
		} else if (dq.back() <= k) {
			dq.pop_back();
			ans++;
		} else
			break;
	}
	cout << ans << '\n';

	return 0;
}
