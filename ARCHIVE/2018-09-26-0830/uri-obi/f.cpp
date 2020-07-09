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
#define X real()
#define Y imag()
#define mp make_pair
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const int INF = 1e9;
  
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e6+10;

int n;
vector<int> arr(N, 0);

int main ()
{
  while (scanf ("%d", &n) != EOF) {
    //printf ("%d\n", n);
    int x, pos;
    for (int i = 0; i < n; i++) {
      scanf ("%d", &arr[i]);
    }
    scanf ("%d", &x);
    auto it = lower_bound (arr.begin(), arr.begin()+n, x);
    pos = it-arr.begin()+1;
    //printf ("%d\n", pos);
    int aux = 2;
    bool ans = true;
    while (aux <= pos) {
      if (pos%aux == 0) {
	//printf ("N\n");
	ans = false;
	break;
      } else
	pos = pos-(pos/aux);
      aux++;
    }
    if (ans)
      printf ("Y\n");
    else
      printf ("N\n");
  }
  
  return 0;
}
