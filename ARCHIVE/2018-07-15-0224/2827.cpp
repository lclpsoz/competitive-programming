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
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 1e5+10;

char arr[MAXN];
char aux[3];
map<string, int> mp;

int main ()
{
  scanf ("%[^\n]", arr);
  arr[0] = tolower (arr[0]);
  for (int i = 1; arr[i] != '\0'; i++) {
    arr[i] = tolower(arr[i]);
    aux[0] = arr[i-1];
    aux[1] = arr[i];
    mp[aux]++;
  }
  int val = -1;
  string st;
  for (pair<string, int> p : mp)
    if (p.y > val) {
      val = p.y;
      st = p.x;
    }
  cout << st << ':' << val << '\n';

  return 0;
}
