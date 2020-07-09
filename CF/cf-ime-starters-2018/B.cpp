#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

// -----------------
#define x first
#define y second
#define len(x) ((int)(x).size())

// --------

const int M = 1e3 + 10, P = 2e3 + 10;

int wkit, m;
int w[M];
char name[M][15];
int dp[M][P];
int reach;

int solve(int i = 0, int sum = 0){
  if(sum >= reach) return sum;
  if(i == m) return 1e9;
  
  int &ret = dp[i][sum];
  if(ret == -1){
    ret = min(solve(i + 1, sum), solve(i + 1, sum + w[i]));
  }
  return ret;
}

void rec(vector<int> &idx, int i = 0, int sum = 0){
  if(sum >= reach) return;
  
  if(solve(i, sum) == solve(i + 1, sum)){
    rec(idx, i + 1, sum);
    return;
  }
  idx.push_back(i);
  rec(idx, i + 1, sum + w[i]);
}

int main () {
  scanf("%d %d", &wkit, &m);
  for(int i = 0; i < m; i++){
    scanf("%s %d", name[i], &w[i]);
  }
  int n;
  scanf("%d", &n);
  while(n--){
    memset(dp, -1, sizeof(dp));
    
    scanf("%d", &reach);
    reach = (reach + 1)/2;
    reach -= wkit;
    
    //printf("reach = %d, solve = %d\n", reach, solve());
    
    if(solve() < 1e9){
      vector<int> idx;
      rec(idx);
      printf("%d", len(idx));
      for(int x : idx) printf(" %s", name[x]);
      printf("\n");
    }else{
      printf("-1\n");
    }
  }
  
  return 0;
}
