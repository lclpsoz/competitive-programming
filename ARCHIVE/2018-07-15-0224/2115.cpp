
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

const int MAXN = 1e4+10;

int n;
int arr[MAXN];

int main () {
  int d, p;
  while (scanf ("%d", &n) != EOF) {
    while (n--) {
      scanf ("%d %d", &d, &p);
      arr[d] += p;
    }
    int ans = 0;
    for (int i = 0; i < MAXN; i++) {
      if (arr[i])
	if (ans >= i)
	  ans += arr[i];
	else
	  ans = i+arr[i];
      arr[i] = 0;
    }
    printf ("%d\n", ans);
  }
  
  return 0;
}
