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

const int MOD = 1e9+7;

ll powll (ll b, int e) {
	ll r = 1;
	while (e) {
		if (e&1)
			r=(r*b)%MOD;
		b = (b*b)%MOD;
		e>>=1;
		// cout << e << '\n';
	}

	return r;
}

int brute (char now, int n) {
	if (n == 0 && now == 'D')
		return 1;
	if (n == 0)
		return 0;
	int r = 0;
	for (char c = 'A'; c < 'E'; c++)
		if (c != now)
			r += brute (c, n-1);

	return r;
}

ll func (int n) {
	ll abc, d;
	abc = 1;
	d = 0;
	n-=3;
	while (n--) {
		ll aux = d;
		d = 3*abc;
		abc = (2*abc+aux)%MOD;
	}

	return (6*abc+3*d)%MOD;
}

int main ()
{
	int n;
	cin >> n;
	if (n == 1)
		cout << "0" << '\n';
	else if (n == 2)
		cout << "3" << '\n';
	else
		cout << func (n) << '\n';

	return 0;
}
