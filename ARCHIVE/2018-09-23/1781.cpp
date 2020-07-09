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

const int S = 1e4+10;

char str[S];
ll pv, pc;
int opt;
vector<char> vog, cons;

int main () {
  int tests, q, x;
  scanf ("%d", &tests);
  for (int t = 1; t <= tests; t++) {
    vog.clear (); cons.clear();
    pv = pc = 0;
    scanf ("%s", str);
    scanf ("%d", &q);
    for (int i = 0; str[i] != '\0'; i++) {
      char c = str[i];
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
	str[i] = '0';
	vog.push_back (c);
      } else {
	str[i] = '1';
	cons.push_back (c);
      }	
    }

    printf ("Caso #%d:\n", t);
    while (q--) {
      scanf ("%d", &opt);
      if (opt == 0) {
	scanf ("%d", &x);
	pv -= x;
      } else if (opt == 1) {
	scanf ("%d", &x);
	pc -= x;
      } else {
	if (len (vog))
	  pv = mod (pv, len (vog));
	if (len (cons))
	  pc = mod (pc, len (cons));
	for (int i = 0; str[i] != '\0'; i++) {
	  if (str[i] == '0') {
	    putchar (vog[pv++]);
	    if (pv == len (vog))
	      pv = 0;
	  } else {
	    putchar (cons[pc++]);
	    if (pc == len (cons))
	      pc = 0;
	  }
	}
	putchar ('\n');
      }
    }
  }
  
  return 0;
}
