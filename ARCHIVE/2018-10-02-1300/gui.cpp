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

int i = 0;

arvore transforma (, int positon, arvore r)
{
  int aux = 0;
  if(str[i+1] == ')')
    return NULL;
  else {
    int bol = 0;
    while(!bol){
      aux += string[i+1] - '0';
      if(str[i+2] != '('){
	aux *= 10;
      }
      else bol = 1;
      i++;
    }
    r = insere2(aux);
    i++;
    r->esq = transforma(string, i, r->esq);
    r->dir = transforma(string, i, r->dir);
  }
  return r;
}


int main () {
  
  return 0;
}
