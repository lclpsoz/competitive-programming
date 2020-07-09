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

int n, m;
vector<int> g[N];
int dp[N][2];

int solve(int u, int p, bool can){
  int &ret = dp[u][can];
  if(ret == -1){
    int mark = -1e9;
    if(can){
      mark = 1;
      for(int v : g[u]) if(v != p){
        mark += solve(v, u, false);
      }
    }
    int not_mark = 0;
    for(int v : g[u]) if(v != p){
      not_mark += solve(v, u, true);
    }
    ret = max(mark, not_mark);
  }
  return ret;
}

int main () {
  scanf("%d %d", &n, &m);
  assert(m == n - 1);
  
  for(int i = 1; i < n; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  memset(dp, -1, sizeof(dp));
  printf("%d\n", solve(1, 1, true));
  return 0;
}
