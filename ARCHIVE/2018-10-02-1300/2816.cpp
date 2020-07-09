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

int n, q;
int x, y;
bool vis[N];
char arr[N], ch;
vector<int> adj[N];

bool dfs (int v) {
  if (vis[v])
    return true;
  vis[v] = true;
  if (ch != '*' && arr[v-1] != '*' && ch != arr[v-1])
    return false;
  if (arr[v-1] != '*')
    ch = arr[v-1];
  for (int u : adj[v])
    if (!dfs (u))
      return false;
  return true;
}



int main () {
  scanf ("%d %d", &n, &q);
  scanf ("%s", arr);
  for (int i = 0; i <= n/2; i++) {
    if (arr[i] != '*' && arr[n-i-1] != '*' && arr[i] != arr[n-i-1]) {
      printf ("0\n");
      return 0;
    }
    adj[i+1].push_back (n-i);
    adj[n-i].push_back (i+1);
  }
  
  for (int i = 0; i < q; i++) {
    scanf ("%d %d", &x, &y);
    adj[x].push_back (y);
    adj[y].push_back (x);
  }

  ll ans = 1;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      ch = '*';
      if (!dfs (i)) {
	printf ("0\n");
	return 0;
      }
      if (ch == '*')
	ans = mod (ans*26);
    }
  printf ("%lld\n", ans);
  
  return 0;
}
