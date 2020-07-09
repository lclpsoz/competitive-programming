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

const int N = 1e3 + 10;

int g[N][N], par[N];
bool vis[N];

int main () {
  int n;
  scanf("%d", &n);
  for(int i = 2; i <= n; i++){
    for(int j = 1; j < i; j++){
      int x;
      scanf("%d", &x);
      g[i][j] = g[j][i] = x;
    }
  }
  
  int ans = 0;
  
  priority_queue<pair<int, pair<int, int>>> s;
  s.push({0, {1, 1}});
  while(!s.empty()){
    int cost = s.top().x, u = s.top().y.x, p = s.top().y.y; s.pop();
    
    if(!vis[u]){
      vis[u] = true;
      
      ans += cost;
      
      par[u] = p;
      
      for(int v = 1; v <= n; v++){
        if(!vis[v]){
          s.push({g[u][v], {v, u}});
        }
      }
    }
  }
  
  printf("%d\n", ans);
  for(int i = 2; i <= n; i++){
    printf("%d\n", par[i]);
  }

  return 0;
}
