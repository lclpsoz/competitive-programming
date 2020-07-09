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


bool operator< (const pii &x, const pii &y)  {
	cout << "asdf\n";
	return x.x < y.x;
}

int main ()
{
	vector<pii> v;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		v.pb ({x, x});
	}
	for (auto u : v)
		cout << u.x << '\n';

	sort (v.begin(), v.end());

	for (auto u : v)
		cout << u.x << '\n';

	return 0;
}
