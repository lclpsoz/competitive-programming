#include <bits/stdc++.h>
using namespace std;
#define MAXN 109
#define INF (1<<25)
#define state dp[mask][i]

int K;
int dist[MAXN][MAXN], X[MAXN];
int dp[(1 << 16) + 1][17], distp[20][20];

bool isprime(int n){
  for(int i=2; i*i <= n; i++){
    if (n % i == 0) return false;
  }
  return true;
}

int func (int msk, int p) {
  if (msk+1 == 1<<K)
    return distp[p][0];
  int &ret = dp[msk][p];
  if (ret != -1)
    return ret;
  ret = 2e9;
  for (int i = 1; i < K; i++)
    if (!(msk & 1<<i))
      ret = min (ret,
		 func ((msk | (1<<i)), i) + distp[i][p]);

  return ret;
}

int main() {
  int N, M;
  int pid[20];
  while(scanf("%d %d", &N, &M) != EOF){
    memset (dp, -1, sizeof dp);
    K = 0;
    pid[K++] = N+1;
    for(int i=1; i<=N; i++){
      scanf("%d", &X[i]);
      if (isprime(X[i])){
	pid[K++] = i;
      }
    }
    //printf("K = %d\n", K);
    for(int i=1; i<=N+1; i++){
      for(int j=1; j<=N+1; j++){
	dist[i][j] = INF;
      }
      dist[i][i] = 0;
    }
    while(M-->0){
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      dist[u][v] = min(dist[u][v], w);
      dist[v][u] = min(dist[v][u], w);
    }
    for(int k=1; k<=N+1; k++){
      for(int i=1; i<=N+1; i++){
	for(int j=1; j<=N+1; j++){
	  dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	}
      }
    }
    for(int i=0; i<K; i++){
      for(int j=0; j<K; j++){
	distp[i][j] = dist[pid[i]][pid[j]];
      }
    }
    printf("%d\n", func (1, 0));
  }
  return 0;
}
