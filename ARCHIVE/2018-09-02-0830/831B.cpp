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

string s1, s2;
map<char, char> conv;

int main ()
{
  cin >> s1 >> s2;
  for (int i = 0; i < 26; i++) {
    conv[s1[i]] = s2[i];
    conv[s1[i]-'a'+'A'] = s2[i]-'a'+'A';
  }
  cin >> s1;
  for (int i = 0; i < (int)s1.size(); i++) {
    if (conv.count (s1[i]))
      putchar (conv[s1[i]]);
    else
      putchar (s1[i]);
  }
  putchar ('\n');
   
  return 0;
}
