#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
#define len(x) (int)x.size()
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 2e5+10;

char a[MAXN];
char b[MAXN];

int main ()
{
	scanf ("%s", a);
	scanf ("%s", b);
	int s1 = strlen (a);
	int s2 = strlen (b);
	int ss1 = s1;
	int ss2 = s2;
	while (s1 > -1 && s2 > -1)
		if (a[s1] == b[s2]) {
			--s1; --s2;
		} else {
			break;
		}
	++s1; ++s2;
	printf ("%d\n", s1+s2);

  return 0;
}
