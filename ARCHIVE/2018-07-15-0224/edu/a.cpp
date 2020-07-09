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

ll n, m, a, b;

int main ()
{
	scanf ("%lld %lld %lld %lld", &n, &m, &a, &b);

	ll aux = n/m;
	ll ans1 = (n-(m*aux))*b;
	ll ans2 = ((m*(aux+1)-n))*a;

	printf ("%lld\n", min (ans1, ans2));

	return 0;
}
