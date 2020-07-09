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

int mdc(int a, int b) {
	if(b == 0) return a;
	return mdc(b, a%b);
}

int main ()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << (	4*mdc(a,b) +
				4*mdc(a,c) +
				4*mdc(b,c)		) << '\n';

	return 0;
}
