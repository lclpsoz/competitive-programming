#include <bits/stdc++.h>
#define len(x) ((int)(x).size())
#define x first
#define y second
using namespace std;
typedef long long ll;

const int N = 2010, MOD = 1e9 + 7;

bool C[N][N];
int qtd[64];

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    unsigned long long x;
    scanf("%llu", &x);
    for(int j = 0; j < 64; j++){
      if(x & (1ULL << j)) qtd[j]++;
    }
  }
	
  C[0][0] = 1;
  for(int i = 1; i <= n; i++){
    C[i][0] = 1;
    for(int j = 1; j <= i; j++){
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%2;
    }
  }
	
  int ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < 64; j++){
      if(C[qtd[j]][i] == 1) ans = (ans + (1ULL << j))%MOD;
    }
  }
  printf("%d\n", ans);
  return 0;
}
