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

int arr[12];

int main ()
{
  int n;
  scanf ("%d", &n);
  vector<int> v;
  int qnt  = 0;
  while (n) {
    v.pb (n%10);
    qnt = max (qnt, v.back());
    n /= 10;    
  }
  int aux = 1;
  for (int z : v) {
    for (int i = 0; i < z; i++)
      arr[i] += aux;
    aux *= 10;
  }
  printf ("%d\n", qnt);
  for (int i = 0; i < qnt; i++)
    printf ("%d ", arr[i]);
  putchar ('\n');

  return 0;
}
