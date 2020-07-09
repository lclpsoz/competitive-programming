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

const int MAXN = 1e5+10;
const int MOD = 1e9+7;

int n;
int fat[MAXN];
char arr[MAXN];
int qnt[500];

int exp (int b, int e) {
  ll r = 1;
  while (e) {
    if (e&1)
      r = (r*b)%MOD;
    b = (b*1LL*b)%MOD;
    e >>= 1;
  }

  return r;
}

int inv (int x) {
  return exp (x, MOD-2);
}

void Ffat () {
  fat[0] = 1;
  for (int i = 1; i <= n; ++i)
    fat[i] = (fat[i-1]*1LL*i)%MOD;
}

int main ()
{
  scanf ("%s", arr);
  n = strlen (arr);
  Ffat ();
  for (int i = 0; i < n; ++i)
    ++qnt[arr[i]];
  int ans = fat[n];
  for (int i = 'a'; i <= 'z'; ++i)
    if (qnt[i])
      ans = (ans*1LL*inv (fat[qnt[i]]))%MOD;
  printf ("%d\n", ans);
  
  return 0;
}
