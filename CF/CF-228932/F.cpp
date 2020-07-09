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

int n, m;
char arr[5], arr2[5];
map<string, int> dict;
vector<int> adj[15];
int group[15];

int backTrack (int v = 0, int msk = 0) {
  if (v == n) {
    /*
    if (__builtin_popcount (msk) == 1) {
      for (int i = 0; i < n; i++)
	printf ("%d ", group[i]);
      putchar ('\n');
    }
    */
    return __builtin_popcount (msk);
  }
  int r = 20;
  for (int i = 0; i < 20; i++) {
    if (msk & 1<<i) {
      bool test = true;
      for (int u : adj[v])
	if (group[u] == i) {
	  test = false;
	  break;
	}
      if (test) {
	group[v] = i;
	r = min (r, backTrack (v+1, msk | 1<<i));
      }
    } else {
      group[v] = i;
      r = min (r, backTrack (v+1, msk | 1<<i));
      break;
    }
  }

  return r;
}

int main () {
  scanf ("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf ("%s", arr);
    dict[arr] = i;
  }

  while (m--) {
    scanf ("%s %s", arr, arr2);
    int u = dict[arr];
    int v = dict[arr2];
    if (u > v)
      swap (u, v);
    adj[v].push_back (u);
  }

  printf ("%d\n", backTrack ());
  
  
  return 0;
}
