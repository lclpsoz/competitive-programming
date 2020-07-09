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

const int MAXN = 1010;

int a[MAXN];
vector<int> v;

int main ()
{
	int n;
	cin >> n;
	int ans= 0 ;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		if (a[i] == 1) {
			++ans;
			if (i > 0)
				v.pb (a[i-1]);
		}
	}
	v.pb (a[n-1]);
	cout << ans << '\n';
	for (int xx : v)
		printf ("%d ", xx);
	putchar ('\n');


  return 0;
}
