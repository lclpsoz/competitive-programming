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


string str;

int main () {
  ios::sync_with_stdio(false);
  cin.tie (0);
  while (getline (cin, str)) {
    for (int i = 0; i < len(str);) {
      char arr[10];
      int p = 0;
      for (; i < len (str) && str[i] != ' '; i++)
	arr[p++] = str[i];
      arr[p] = '\0';
      int v;
      sscanf (arr, "%o", &v);
      //printf ("%o:", v);
      if (v == 64)
	putchar (' ');
      else if (129 <= v && v <= 137) {
	v = v-129+'a';
	//printf ("%d\n", v);
	putchar (v);
      } else if (145 <= v && v <= 153) {
	putchar (v-145+'j');
      } else if (162 <= v && v <= 169) {
	putchar (v-162+'s');
      } else if (193 <= v && v <= 201) {
	putchar (v-193+'A');
      } else if (209 <= v && v <= 217) {
	putchar (v-209+'J');
      } else if (226 <= v && v <= 233) {
	putchar (v-226+'S');
      } else if (240 <= v && v <= 249) {
	v = v-240+'0';
	putchar (v);
      } else
	assert(false);
      while (i < len(str) && str[i] == ' ')
	++i;
    }
    putchar ('\n');
  }
  
  return 0;
}
