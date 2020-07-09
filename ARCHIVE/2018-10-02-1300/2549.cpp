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

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int n, y;
char str[110];
char aux[110], p;
unordered_set<string> st;

int main () {
  while (scanf ("%d %d", &n, &y) != EOF) {
    st.clear();
    getchar ();
    int ans = 0;
    while (n--) {
      scanf ("%[^\n]", str);
      getchar();

      p = 0;
      char *tok = strtok (str, " ");
      while (tok != NULL) {
	aux[p++] = tolower(tok[0]);
	tok = strtok(NULL, " ");
      }
      aux[p] = '\0';
      if (!st.count (aux))
	st.insert (aux);
      else
	++ans;
    }
    printf ("%d\n", ans);
  }
  
  return 0;
}
