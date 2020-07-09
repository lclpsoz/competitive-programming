#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
#define len(x) (int)x.size()
#define X real()
#define Y imag()
#define mp make_pair
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const int INF = 1e9;
  
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

string s1, s2, s3;
map<string, bool> verif;
map<string, vector<string>> adj;
set<string> s;

void dfs (string str) {
  if (!verif[str]) {
    //cout << ' ' << str << '\n';
    verif[str] = true;
    for (string u : adj[str])
      dfs (u);
  }
}

int main ()
{
  int n, m;
  scanf ("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2 >> s3;
    //cout << s1 << ' ' << s3 << endl;
    s.insert(s1);
    s.insert(s3);
    adj[s1].pb(s3);
    adj[s3].pb(s1);
  }

  int ans = 0;
  for (string str : s) {
    if (!verif[str]) {
      //cout << str << '\n';
      ans++;
      dfs (str);
    }
  }

  printf ("%d\n", ans);
  

  return 0;
}
