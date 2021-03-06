#include <bits/stdc++.h>

using namespace std;

#define len(x) ((int)(x).size())
#define x first
#define y second

using ll = long long;
using llu = unsigned long long;
using ld = long double;

const int N = 455;

int n, k;
char s[N];
int dp[2][N][N];

/*
  int solve(int i, int cur, int to_del){
  if(i == n) return 0;
	
  int ret = 0;
  if(s[i] == '0'){
  ret = solve(i + 1, 0, to_del);
  }else{
  ret = cur + 1 + solve(i + 1, cur + 1, to_del);
  if(to_del > 0) ret = min(ret, solve(i + 1, 0, to_del - 1));
  }
  return ret;
  }
*/

void pre(){
  for(int i = n; i >= 1; i--){
    int ii = i & 1;
    for(int cur = 0; cur <= i; cur++){
      for(int to_del = 0; to_del <= n; to_del++){
	int &ret = dp[ii][cur][to_del];
	if(s[i] == '0'){
	  ret = dp[!ii][0][to_del];
	}else{
	  ret = cur + 1 + dp[!ii][cur + 1][to_del];
	  if(to_del > 0) ret = min(ret, dp[!ii][0][to_del - 1]);
	}
      }
    }
  }
}

int main(){
  int qnt;
  scanf ("%d", &qnt);
  while (qnt--) {
    memset (dp, 0, sizeof (dp));
    scanf("%d %d", &n, &k);
    scanf("%s", s + 1);
	
    pre();
	
    for(int i = 0; i <= n; i++){
      int go = dp[1][0][i];
      //printf("i = %d, go = %d\n", i, go);
      if(go <= k){
	printf("%d\n", i);
	break;
      }
    }
  }
  
  return 0;
}
