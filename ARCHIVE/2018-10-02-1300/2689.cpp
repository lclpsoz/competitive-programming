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

int q;
int mat[3][3];
map<int, int> mp;

int main () {
  scanf ("%d", &q);
  while (q--) {
    mp.clear();
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
	scanf ("%d", &mat[i][j]);
	if (j == 1)
	  mp[abs(mat[i][j]-mat[i][j-1])]+=2;
	else if (j == 2)
	  mp[abs(mat[i][j]-mat[i][j-1])]++;
      }
    pii ans;
    for (auto p : mp)
      if (p.y > ans.y)
	ans = p;
    vector<int> vec;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
	bool test = true;
	for (int k = 0; k < 3; k++)
	  if (j != k && abs (mat[i][j]-mat[i][k]) == ans.x)
	    test = false;
	if (test)
	  vec.push_back (mat[i][j]);
      }
    printf ("Possiveis maletas: ");
    for (int i = 0; i < len (vec); i++) {
      printf ("%d", vec[i]);
      if (i < len (vec)-1)
	printf (", ");
    }
    printf (";\n");
  }
  
  return 0;
}
