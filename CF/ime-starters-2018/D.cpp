#include <bits/stdc++.h>
using namespace std;

// -----------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

// --------

const int N = 1e5 + 10;

int n;
double a[N], bit[N];

void add(int pos, double val){
  for(int i = pos; i < N; i += (i & -i)){
    bit[i] += val;
  }
}

double sum(int pos){
  double ret = 0;
  for(int i = pos; i >= 1; i -= (i & -i)){
    ret += bit[i];
  }
  return ret;
}

int main () {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%lf", &a[i]);
    add(i, a[i]);
  }
  int q;
  scanf("%d", &q);
  while(q--){
    int t;
    scanf("%d", &t);
    if(t == 1){
      int pos; double val;
      scanf("%d %lf", &pos, &val);
      add(pos, -a[pos]);
      a[pos] = val;
      add(pos, a[pos]);
    }else{
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%.10lf\n", (sum(r) - sum(l - 1))/(r - l + 1));
    }
  }
  
  return 0;
}
