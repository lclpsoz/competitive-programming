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

int n;
map<int, int> mp;

int main ()
{
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		mp[x]++;
	}
	int ans = 0;
	for (pii p : mp) {
		int xx = p.x;
		bool tst = false;
		--mp[xx];
		for (int i = 1073741824; i-xx > 0 && i >= 1 ; i = i >> 1)
			if (mp.count(i-xx) && mp[i-xx] > 0) {
				tst = true;
				break;
			}
		++mp[xx];
		if (!tst)
			ans += p.y;
	}
	printf ("%d\n", ans);

  return 0;
}
