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

const int N = 22, MSK = (1<<19) + 1, INF = 2e9;

int n, a;
char str[50];
int mat[N][N];
int dist[N][N], distClean[N][N];
int ans = INF;
int dp[N][MSK];

int solve (int v, int msk) {
  if ((msk+1) == (1<<(n)))
    return 0;
  
  int &r = dp[v][msk];
  if (r != -1) return r;
  r = INF;
  for (int u = 0; u < n; u++)
    if (!(msk&(1<<u))) {
      if (dist[v][u] < distClean[v][u])
        r = min (r, solve (u, msk|(1<<u)) + dist[v][u]);
      else
        r = min (r, solve (u, msk|(1<<u)) + distClean[v][u]);
    }
  
  return r;
}

vector<int> seq;

void rec(int v, int msk){
  seq.push_back(v);
  for(int u = 0; u < n; u++){
    if(!(msk&(1<<u))){
      if (dist[v][u] < distClean[v][u]){
        if(solve(v, msk) == solve (u, msk|(1<<u)) + dist[v][u]){
          rec(u, msk|(1<<u));
          return;
        }
      }else{
        if(solve(v, msk) == solve (u, msk|(1<<u)) + distClean[v][u]){
          seq.push_back(-1);
          rec(u, msk|(1<<u));
          return;
        }
      }
    }
  }
}

int main () {
  memset (dp, -1, sizeof dp);
  
  scanf ("%d %d", &n, &a);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 21; j++) {
      scanf ("%s", str);
      int val = 0, aux = 0;
      for (int k = 20; k >= 0; k--) {
	      if (str[k] == '1')
	        val += 1<<aux;
	      ++aux;
      }
      mat[i][j] = val;
    }
    
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      int d1, d2;
      d1 = 0;
      d2 = a;
      for (int k = 0; k < 21; k++) {
	      d1 += __builtin_popcount (mat[i][k]^mat[j][k]);
	      d2 += __builtin_popcount (mat[j][k]);
      }

      dist[i][j] = d1;
      distClean[i][j] = d2;
    }

  int start = -1;
  for (int i = 0; i < n; i++) {
    int d = 0;
    for (int j = 0; j < 21; j++)
      d += __builtin_popcount (mat[i][j]);
    int go = solve(i, 1<<i) + d;
    if (go < ans){
      ans = go;
      start = i;
    }
  }

  printf ("%d\n", ans);

  rec(start, 1<<start);

  for(int i = 0; i < len(seq); i++){
    if(i > 0) printf(" ");
    if (seq[i] == -1)
      putchar ('*');
    else
      printf("%d", seq[i] + 1);
  }
  printf("\n");
  return 0;
}
