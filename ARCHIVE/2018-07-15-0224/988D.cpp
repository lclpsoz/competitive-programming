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

int n, x;
vector<int> v;
vector<int> arr[MAXN];

int main ()
{
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf ("%d", &x);
    v.pb (x);
  }
  sort (v.begin(), v.end());
  int ans = 1;
  vector<int> vv;
  vv.pb (v[0]);
  vv.pb (-1);
  vv.pb (-1);
  for (int i = n-2; i >= 0; --i) {
    for (int j = 1; j <= 2e9; j<<=1) {
      //      printf ("%d %d\n", i, j);
      int val = *(v.begin()+i);
      auto q = lower_bound (v.begin()+i+1, v.end(), val+j);
      if (q == v.end()) break;
      //      printf ("--\n");
      int p = q-v.begin();
      if (*q == val+j) {
	//	printf ("--\n");
	arr[i].pb (j);
	if (ans == 1) {
	  ans = 2;
	  vv[0] = val;
	  vv[1] = *q;
	}
	if (ans == 2) {
	  if (arr[p].size() && (*lower_bound (arr[p].begin(), arr[p].end(), j)) == j) {
	    ans = 3;
	    vv[0] = val;
	    vv[1] = *q;
	    vv[2] = *q+j;
	    break;
	  }
	}
      }
    }
    if (ans == 3) break;
  }
  printf ("%d\n", ans);
  for (int i = 0; i < ans; i++)
    printf ("%d ", vv[i]);
  putchar ('\n');

  return 0;
}
