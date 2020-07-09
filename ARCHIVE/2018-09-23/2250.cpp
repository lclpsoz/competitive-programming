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
int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

int n;
char str[20];
vector<pair<int, string>> vec;

int main () {
  int t = 1;
  while (scanf ("%d", &n), n) {
    vec.clear();
    for (int j = 0; j < n; j++) {
      scanf ("%s", str);
      int mini = 1e9;
      int maxi = -1e9;
      int acu = 0, x;
      for (int i = 0; i < 12; i++) {
	scanf ("%d", &x);
	maxi = max (x, maxi);
	mini = min (x, mini);
	acu += x;
      }
      vec.push_back ({-(acu-maxi-mini), str});
    }
    sort (vec.begin(), vec.end());
    printf ("Teste %d\n", t++);
    for (int i = 0, j = 1; i < n; i++) {
      printf ("%d %d ", j, -vec[i].x);
      cout << vec[i].y << '\n';
      if (!(i < n-1 && vec[i+1].x == vec[i].x)) {
	if (i+1 != j)
	  j = i+1;
	j++;
      }
    }
    putchar ('\n');
  }
  
  return 0;
}
