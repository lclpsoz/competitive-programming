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

int t, n;
char a[10];
vector<int> vec;
vector<int> ans;

int sum () {
  int r = 0;
  for (int i = 0; i < 5; i++) {
    //printf ("%d ", vec[i]);
    r += vec[i]*11111*24;
  }
  //putchar ('\n');
  //printf ("%d\n", r);
  return r;
}

int conv () {
  int r = 0;
  for (int i = 0; i < 5; i++) {
    r += vec[i]*(int)pow(10, 4-i);
  }
  return r;
}

bool func () {
  int v = (1<<5)-1;
  int lim = 1<<10;
  bool r = false;
  int qnt = 0;
  while (v < lim) {
    if (__builtin_popcount (v) != 5) {
      ++v;
      continue;
    }
    ++qnt;
    vec.clear();
    for (int i = 0; i < 10; i++)
      if (1<<i & v)
	vec.push_back (i);
    if (sum() == n) {
      r = true;
      //printf ("%d:\n", sum());
      ans.push_back (conv ());
    }
    ++v;
  }
  //printf ("========QNT = %d\n", qnt);
  return r;
    
}

int main () {
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d", &n);
    if (!func ())
      printf ("impossivel\n");
    else {
      sort (ans.begin(), ans.end());
      for (int x : ans) {
	putchar ('{');
	stack<int> st;
	for (int i = 0; i < 5; i++) {
	  st.push(x%10);
	  x/=10;
	}
	while (st.size() > 1) {
	  printf ("%d,", st.top());
	  st.pop();
	}
	printf ("%d}\n", st.top());
	st.pop();
      }
      ans.clear();
    }
    putchar ('\n');
  }
  
  return 0;
}
