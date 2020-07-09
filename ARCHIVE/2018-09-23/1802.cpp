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
int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

int n, k;
priority_queue<int> pq;
int qnt[20], mat[20][20];

void func () {
  vector<int> v(6, 0);
  while (v[5] == 0) {
    int aux = 0;
    for (int i = 0; i < 6; i++)
      aux += mat[i][v[i]];
    //printf ("%d\n", aux);
    pq.push (-aux);
    if (len(pq) > k)
      pq.pop();
    //printf ("| %d\n", len (pq));
    v[0]++;
    for (int i = 0; i < 5; i++)
      if (v[i] >= qnt[i]) {
	v[i] = 0;
	v[i+1]++;
      }
  }
}

int main () {
  for (int i = 0; i < 5; i++) {
    scanf ("%d", &n);
    qnt[i] = n;
    for (int j = 0; j < n; j++)
      scanf ("%d", &mat[i][j]);
  }
  scanf ("%d", &k);
  //printf ("%d\n", k);
  func ();
  ll ans = 0;
  while (!pq.empty()) {
    ans += -pq.top();
    pq.pop();
  }
  printf ("%lld\n", ans);
  
  return 0;
}
