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

const int MOD = 1e9 + 7;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

// --------

const int MAX = 3e5 + 10;

int fact[MAX];

void pre(){
  fact[0] = 1;
  for(int i = 1; i < MAX; i++){
    fact[i] = mod(fact[i - 1]*1LL*i);
  }
}

int powmod(int a, int x){
  int ret = 1;
  while(x){
    if(x & 1) ret = mod(ret*1LL*a);
    a = mod(a*1LL*a), x >>= 1;
  }
  return ret;
}

int inv(int a){
  return powmod(a, MOD - 2);
}

int arranjo(int n, int p){
  if(n < p) return 0;
  return mod(fact[n]*1LL*inv(fact[n - p]));
}

int main () {
  pre();
  
  int n, c;
  scanf("%d %d", &n, &c);
  
  int x = c - 2*n;
  int ans = mod(arranjo(x, n)*1LL*powmod(6, n));
  printf("%d\n", ans);
  
  return 0;
}
