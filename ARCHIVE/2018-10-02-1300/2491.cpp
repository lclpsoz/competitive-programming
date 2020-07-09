#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-3;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

using pp = pair<int, pair<double, int>>;
const int N =2e4+10;

int n;
int p;
int d, c;

double r, avr, he;
vector<pp> vec;
pp dp[N];

int main () {
  while (scanf ("%d %d", &n, &d) != EOF && n) {
    for (int i = 0; i < N; i++)
      dp[i] = {-1, {-1, -1}};
    dp[0] = {d, {0, 0}};
    vec.clear();
    avr = 0, he = 0;
    
    for (int k = 0; k < n; k++) {
      scanf ("%d %d %lf", &p, &c, &r);
      vec.push_back ({p, {r, c}});
      avr += r;
      //printf ("-> %d %d %f\n", p, c, r);
      for (int i = N-1; i >= p; i--)
	if (dp[i-p].x != -1 && cmp (dp[i-p].x, c) >= 0 && dp[i].x == -1) {
	  //printf ("|%d %f\n", i-p, dp[i-p].y.x);
	  dp[i] = {dp[i-p].x-c,
		   {dp[i-p].y.x + r, dp[i-p].y.y + 1} };
	  //printf (" |%d %f\n", i, dp[i].y.x);
	}
    }
    for (int i = N-1; i > 0; i--)
      if (dp[i].x != -1) {
	//printf("%f %d\n", dp[i].y.x, dp[i].y.y);
	he = dp[i].y.x / dp[i].y.y;
	//printf ("  %Lf\n", he);
	break;
      }
    avr /= n;
    if (cmp (he, avr) < 1) {
      printf ("%0.2lf NO!\n", avr);
    }
    else {
      printf ("%0.2lf\n", he);
    }
    //printf ("________________________________\n");
  }
  
  return 0;
}
