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


int main ()
{
	int a;
	float b;
	char c;
	char d[100];
	scanf ("%d %f %c %[^\n]", &a, &b, &c, d);
	printf ("%d%f%c%s\n", a, b, c, d);
	printf ("%d\t%f\t%c\t%s\n", a, b, c, d);
	printf("%10d%10.6f%10c%10s\n", a, b, c, d);

	return 0;
}
