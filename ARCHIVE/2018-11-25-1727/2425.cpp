#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int cxs, n;
queue<pii> q;
int arr[12];

int main () {
  scanf ("%d %d", &cxs, &n);
  while (n--) {
    int st, d;
    scanf ("%d %d", &st, &d);
    q.push ({st, d});
  }

  int ans = 0;
  for (int i = 0; i < cxs; i++)
    arr[i] = q.front().x;
  while (!q.empty()) {
    int mini = 2e9, pos = 0;
    for (int i = 0; i < cxs; i++)
      if (arr[i] < mini) {
	mini = arr[i];
	pos = i;
      }

    arr[pos] = max (arr[pos], q.front().x);
    //printf ("%d %d\n", arr[pos], q.front().x);
    if (arr[pos] - q.front().x > 20)
      ++ans;
    arr[pos] += q.front().y;
    q.pop();

    /*
    printf ("[%d] ", ans);
    for (int i = 0; i < cxs; i++)
      printf ("%d ", arr[i]);
    putchar ('\n');
    */
  }
  printf ("%d\n", ans);
  
  return 0;
}
