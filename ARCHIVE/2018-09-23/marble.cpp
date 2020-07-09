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

const int MOD = 1e9+7;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5+10;

queue<int> houses[N];
vector<int> vec;
queue<int> vals[310];
set<int> s;

int main () {
  int n, k, x;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf ("%d", &k);
    while (k--) {
      scanf ("%d", &x);
      houses[i].push (x);
    }
  }
  for (int i = 0; i < n; i++) {
    s.insert (houses[i].front());
    vals[houses[i].front()].push (i);
    //printf ("%d: %d\n", i, len (houses[i]));
  }
  //printf ("asidhfuiashfiuaisudhfuas\n");
  
  while (!s.empty()) {
    int v = *(s.begin());
    int st = vals[v].front();
    //printf (":::: %d %d\n", v, st);
    vec.push_back (v);
    
    houses[st].pop(); // Removes v from queue
    //printf ("sz: %ld\n", houses[st].size());
    int u = (houses[st].size() > 0 ? houses[st].front() : - 1);
    //printf ("%d %d\n", v, u);
    //printf ("szSET: %ld\n", s.size());
    // Removes old
    if (u != v) {
      //printf ("IN %d: %d\n", v, len (vals[v]));
      vals[v].pop();
      //printf ("IN %d: %d\n", v, len (vals[v]));
      if (vals[v].empty())
	s.erase (s.begin());
    }
    // Add new value, if it exist
    if (u != v && u != -1) {
      if (v != u && vals[u].empty())
	s.insert (u);
      vals[u].push (st);
    }
    //putchar ('\n');
  }
  
  ll ans = 0;
  int aux = 365;
  while (!vec.empty()) {
    ans = mod (ans + vec.back()*1LL*aux);
    //printf ("%d\n", vec.back());
    vec.pop_back();
    aux = mod (aux*1LL*365);
  }

  printf ("%lld\n", ans);
  
  return 0;
}
