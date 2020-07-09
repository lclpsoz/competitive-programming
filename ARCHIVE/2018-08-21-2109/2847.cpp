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

char c;
int arr[1000];
char s[] = "I love you!";
char s2[] = "o";
char s1[] = "Ilveyu!";
// 2: o, ' '

int main ()
{   
  while (c = getchar(), c != EOF) {
    ++arr[c];
  }
  int ans = INF;
  ans = arr[s2[0]]/2;
  for (int i = 0; s1[i] != '\0'; i++)
    ans = min (ans, arr[s1[i]]);
  cout << ans << '\n';

  return 0;
}
