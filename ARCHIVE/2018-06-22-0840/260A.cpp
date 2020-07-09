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

const int MAXN = 1e5+10;

char str[MAXN];

int main ()
{
	int a, b, n;
	cin >> a >> b >> n;
	a*=10;
	for (int i = 0; i < 10; i++) {
		if ((a+i)%b == 0) {
			a+=i;
			break;
		}
	}
	if (a%b != 0)
		printf ("-1\n");
	else {
		for (int i = 1; i < n; i++)
			str[i-1] = '0';
		printf ("%d%s\n", a, str);
	}

	return 0;
}
