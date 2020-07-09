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

map<string, int> cv;
string arr[20];

int main ()
{
  cv["X"] = 10;
  cv["/"] = 10;
  for (int i = 0; i <= 9; i++) {
    cv[to_string(i)] = i;
    for (int j = 0; i+j < 10; j++)
      cv[to_string(i)+to_string(j)] = i+j;
  }
  for (int i = 0; i <= 9; i++)
    cv[to_string(i)+"/"] = 10;
  //for (auto p : cv)
  //  cout << p.x << ' ' << p.y << '\n';

  for (int i = 0; i < 10; i++)
    cin >> arr[i];
  int ans = 0;
  for (int i = 0; i < 8; i++) {
    ans += cv[arr[i]];
    if (arr[i] == "X") {
      ans += cv[arr[i+1]];
      if (arr[i+1] == "X")
	ans += cv[arr[i+2].substr(0, 1)];
    } else if (arr[i][1] == '/')
      ans += cv[arr[i+1].substr(0, 1)];
    //printf ("%d: %d\n", i, ans);
  }
  ///// 8
  ans += cv[arr[8]];
  if (arr[8] == "X") {
    if (arr[9][0] == 'X')
      ans += 10 + cv[arr[9].substr (1, 1)];
    else
      ans += cv[arr[9].substr (0, 2)];
  } else if (arr[8][1] == '/') {
    ans += cv[arr[9].substr(0, 1)];
  }
  ///// 9
  if (arr[9][0] == 'X') {
    ans += 10;
    if (arr[9][1] == 'X')
      ans += 10 + cv[arr[9].substr (2, 1)];
    if (arr[9][2] == '/')
      ans += 10;
    else
      ans += cv[arr[9].substr (1, 2)];
  }
  else if (arr[9][1] == '/')
    ans += 10 + cv[arr[9].substr (2, 1)];
  else
    ans += cv[arr[9]];

  printf ("%d\n", ans);
  
  return 0;
}
