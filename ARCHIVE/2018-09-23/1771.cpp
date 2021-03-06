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

int x;
vector<int> vec;
int mat[6][6];

int main () {
  while (scanf ("%d", &x) != EOF) {
    mat[0][0] = x;
    vec.push_back (x);
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++) {
	if (i == 2 && j == 2) continue;
	if (i == 0 && j == 0) continue;
	scanf ("%d", &mat[i][j]);
	vec.push_back (mat[i][j]);
      }
    mat[2][2] = 31;
    bool ok = true;
    for (int i = 0; i < 5; i++)
      if (mat[i][0] <= 0 || mat[i][0] > 15)
	ok = false;
    for (int i = 0; i < 5; i++)
      if (mat[i][1] <= 15 || mat[i][1] > 30)
	ok = false;
    for (int i = 0; i < 5; i++)
      if (mat[i][2] <= 30 || mat[i][2] > 45) {
	ok = false;
      }
    for (int i = 0; i < 5; i++)
      if (mat[i][3] <= 45 || mat[i][3] > 60)
	ok = false;
    for (int i = 0; i < 5; i++)
      if (mat[i][4] <= 60 || mat[i][4] > 75)
	ok = false;
    if (ok)
      printf ("OK\n");
    else {
      ok = true;
      sort (vec.begin(), vec.end());
      for (int i = 0; i < 5; i++)
	if (vec[i] <= 0 || vec[i] > 15)
	  ok = false;
      for (int i = 5; i < 10; i++) {
	//printf ("%d ", vec[i]);
	if (vec[i] <= 15 || vec[i] > 30)
	  ok = false;
      }
      //putchar ('\n');
      for (int i = 10; i < 14; i++)
	if (vec[i] <= 30 || vec[i] > 45)
	  ok = false;
      for (int i = 14; i < 19; i++)
	if (vec[i] <= 45 || vec[i] > 60)
	  ok = false;
      for (int i = 19; i < 24; i++)
	if (vec[i] <= 60 || vec[i] > 75)
	  ok = false;
      printf ("%s\n", ok ? "RECICLAVEL" : "DESCARTAVEL");
    }
    vec.clear();
  }
  
  return 0;
}
