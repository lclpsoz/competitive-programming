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

int a[5];
map<int, bool> mp;

int main ()
{
	for (int i = 0; i < 4; i++) {
		scanf ("%d", &a[i]);
		mp[a[i]] = true;
	}
	printf ("%d\n", 4-len(mp));


  return 0;
}
