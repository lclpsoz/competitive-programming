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

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1e9+7;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int F = 1e4+10;

int n, m;
char c, str[510];
int arr[30], qnt_now[30];


int main () {
  scanf ("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf (" %c", &c);
      arr[c-'a']++;
    }

  int q;
  scanf ("%d", &q);
  while (q--) {
    memset (qnt_now, 0, sizeof qnt_now);
    scanf ("%s", str);
    for (int i = 0; str[i] != '\0'; i++)
      qnt_now[str[i]-'a']++;
    int ans = 1;
    bool test = true;
    for (int i = 0; i <= ('z'-'a'); i++) {
      if (arr[i] < qnt_now[i]) {
	test = false;
	break;
      } else
	for (int j = arr[i]; j > (arr[i]-qnt_now[i]); j--)
	  ans = mod (ans*1LL*j);
    }
    
    if (!test)
      ans = 0;
    printf ("%d\n", ans);
  }   
  
  return 0;
}
