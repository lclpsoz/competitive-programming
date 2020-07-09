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
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 2e5+10;

int n;
vector<pii> v;
int ans[MAXN];

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf ("%d %d", &x, &y);
		v.insert({x, 0});
		v.insert({y, 1});
	}
	sort (v.begin(), v.end());
	int aux = 0;
	int now = v[0].x;
	aux = 1;
	for (int i = 1; i < n; i++) {
		if (v[i].x == now && v[i].y == 0) {
			aux++;
		} else if (v[i].x > now) {
	}


  return 0;
}
