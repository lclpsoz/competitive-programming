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

string str;
int n, m;

int main () {
  scanf ("%d %d", &n, &m);
  cin >> str;
  if (n  == 1)
    for (int i = 0; i < m; i++)
      cout << str;
  else {
    string str_2 = str;
    cout << str;
    int aux = 1;
    for (; aux < len (str); ++aux) {
      bool teste = true;
      for (int i = 0; i+aux < len(str); i++)
	if (str_2[i] != str[i+aux]) {
	  teste = false;
	  break;
	}
      if (teste)
	break;
      //printf ("%d\n", aux);
    }
      
	  
    string ss = str.substr (n-aux);
    for (int i = 0; i < m-1; i++) {
      cout << ss;
    }
  }
  putchar ('\n');
  
  
  return 0;
}
