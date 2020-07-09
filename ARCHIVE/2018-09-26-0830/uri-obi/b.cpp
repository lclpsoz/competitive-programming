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

const int N = 1e5+10;

int n;
stack<int> q;
int arr[N], ans[N];

int main ()
{
  scanf ("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf ("%d", &arr[i]);

  for (int i = n; i >= 1; i--) {
    while (!q.empty() && arr[i] >= q.top())
      q.pop();
    if (!q.empty())
      ans[i] = q.top();
    q.push (arr[i]);
  }

  for (int i = 1; i <= n; i++) {
    ans[i] == 0 ? putchar ('*') : printf ("%d", ans[i]);
    if (i < n)
      putchar (' ');
  }
  putchar ('\n');

  return 0;
}
