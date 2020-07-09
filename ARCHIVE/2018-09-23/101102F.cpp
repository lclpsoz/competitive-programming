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
int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int C = 1e5+10;

char arr[C];

int main () {
  int t;
  scanf ("%d", &t);
  while (t--) {
    vector<pair<int, char>> vec(30, {C, 200});
    scanf ("%s", arr);
    for (int i = 0; arr[i] != '\0'; i++) {
      if (vec[arr[i]-'a'].x == C)
	vec[arr[i]-'a'] = {i, arr[i]};
    }
    sort (vec.begin(), vec.end());
    //printf ("%d %c\n", vec[0].x, vec[0].y);
    char bef, now;
    bef = now = '\0';
    for (int i = 0; i < 26 && bef == '\0'; i++) {
      bef = now = vec[i].y;
      for (int j = i+1; j < 26 && vec[j].x != C; j++)
	now = min (now, vec[j].y);
      //printf ("%c %c\n", bef, now);
      if (now == bef)
	bef = '\0';
    }

    for (int i = 0; arr[i] != '\0'; i++)
      if (arr[i] == now)
	arr[i] = bef;
      else if (arr[i] == bef)
	arr[i] = now;
    printf ("%s\n", arr);
  }
  
  return 0;
}
