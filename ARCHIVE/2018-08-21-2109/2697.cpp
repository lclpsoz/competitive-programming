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

const int N = 1e4+10;

int k, n;
int a[N];
int qnt[1010];
vector<int> inv_qnt[N];
map<int, int> vals;

int main ()
{
  scanf ("%d %d", &k, &n);
  for (int i = 0; i < n; i++) {
    scanf ("%d", &a[i]);
    //printf ("%4d %d ", i, a[i]);
    qnt[a[i]]+=1;
    //printf ("[%d]\t\t", qnt[a[i]]);
    //if (i%4 == 0)
    //  putchar ('\n');
  }
  for (int i = 1; i <= k; i++)
    inv_qnt[qnt[i]].pb (i);

  if (n == 1)
    printf ("-%d\n", a[0]);
  else if (n % k == 0) {
    int aux = n/k;
    if (inv_qnt[aux-1].size() == 1 && inv_qnt[aux+1].size() == 1 && inv_qnt[aux].size() == k-2) {
      int x, y;
      x = inv_qnt[aux+1][0];
      y = inv_qnt[aux-1][0];
      printf ("-%d +%d\n", x, y);
    } else
      printf ("*\n");
  } else if (n % k == k-1) {
    int aux = (n+1)/k;
    if (inv_qnt[aux].size() == k-1 && inv_qnt[aux-1].size() == 1)
      printf ("+%d\n", inv_qnt[aux-1][0]);
    else
      printf ("*\n");
  } else if (n % k == 1) {
    int aux = (n-1)/k;
    if (inv_qnt[aux].size() == k-1 && inv_qnt[aux+1].size() == 1)
      printf ("-%d\n", inv_qnt[aux+1][0]);
    else
      printf ("*\n");
  } else
    printf ("*\n");
    

  return 0;
}
