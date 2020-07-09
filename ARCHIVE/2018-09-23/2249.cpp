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

const int INF = 1e9;

int n;
char str[1010], aux[110];
queue<pair<int, string>> q;
map<string, int> dist;
map<string, vector<string>> adj;
set<string> vis;
set<pair<pair<string, string>, int>> ans;

int main () {
  int t = 1;
  while (scanf ("%d ", &n), n) {
    dist.clear();
    adj.clear();
    for (int k = 0; k < n; k++) {
      scanf ("%[^\n] ", str);
      vector<string> vec;
      for (int i = 0; str[i] != '\0'; i++) {
	int j = 0;
	while (str[i] != ',' && (str[i+1] != '\0')) {
	  aux[j++] = str[i];
	  ++i;
	}
	aux[j] = '\0';
	vec.push_back (aux);
	dist[aux] = INF;
	if (str[i] == ',')
	  ++i;
      }
      for (int i = 0; i < len (vec); i++)
	for (int j = i+1; j < len (vec); j++) {
	  adj[vec[i]].push_back (vec[j]);
	  adj[vec[j]].push_back (vec[i]);
	}
    }

    q.push ({0, "P. Erdos"});
    dist["P. Erdos"] = 0;
    vis.clear();
    while (!q.empty()) {
      string v = q.front().y;
      //cout << "|" << v << '\n';
      int w = q.front().x;
      q.pop();
      if (vis.count (v)) continue;
      vis.insert (v);
      for (string u : adj[v]) {
	//cout << "   " << u << '\n';
	int &dU = dist[u];
	if (dU > w+1) {
	  dU = w+1;
	  //cout << "      push: " << dU << ", " << u << '\n';
	  q.push ({dU, u});
	}
      }
    }

    //printf ("------------------------------------------\n");
    ans.clear();
    for (auto p : dist) {
      if (p.x != "P. Erdos")
	ans.insert ({{p.x.substr (3), p.x.substr (0, 3)}, p.y});
    }
    printf ("Teste %d\n", t++);
    for (auto p : ans) {
      if (p.y == INF)
	cout << p.x.y << p.x.x << ": infinito\n";
      else
	cout << p.x.y << p.x.x << ": " << p.y << '\n';
    }
    putchar ('\n');
    //printf ("------------------------------------------\n");
  }
  
  return 0;
}
