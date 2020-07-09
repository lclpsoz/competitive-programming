#include <stdio.h>
#include <stack>
using namespace std;

#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const int N = 1010;

struct reg {
  int pos, h;
};

int t;
int mat[N][N], mat_qnt[N][N];
stack<reg> sta;

int func (int pos_st, int cut = 0) {
  if (sta.empty() || sta.top().h <= cut)
    return 0;
  int ret = 0;
  int h, len, pos_lst;
  while (!sta.empty() && sta.top().h > cut) {
    reg now = sta.top();
    sta.pop();
    len = pos_st - now.pos + 1;
    pos_lst = now.pos;
    if (!sta.empty() && sta.top().h > cut)
      h = now.h - sta.top().h;
    else
      h = now.h - cut;
    ret += h * ((len*(len+1))/2);
  }
  if (cut)
    sta.push ({pos_lst, cut});
  
  return ret;
}

int main () {
  int r, c;
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d %d", &r, &c);
    for (int i = 1; i <= r; i++)
      for (int j = 1; j <= c; j++) {
	scanf ("%d", &mat[i][j]);
	if (mat[i-1][j] == mat[i][j])
	  mat_qnt[i][j] = mat_qnt[i-1][j]+1;
	else
	  mat_qnt[i][j] = 1;
      }

    ll ans = 0;
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
	if (mat[i][j] != mat[i][j-1])
	  ans += func (j-1);
	else
	  ans += func (j-1, mat_qnt[i][j]);
	if (sta.empty() || sta.top().h != mat_qnt[i][j])
	    sta.push ({j, mat_qnt[i][j]});
      }
      
      ans += func (c);
    }
    
    printf ("%lld\n", ans);
  }
  
  return 0;
}
