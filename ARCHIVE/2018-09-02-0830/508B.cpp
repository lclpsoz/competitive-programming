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

string str;
string maxi = "0";

int main ()
{
  cin >> str;

  int state = 0;
  for (int i = 0; i < (int)str.size(); i++) {
    if ((str[i]-'0')%2 == 0) {
      if (state == 0) {
	swap (str[i], str[str.size()-1]);
	maxi = str;
	if (str[i] > str[str.size()-1])
	  break;
	swap (str[i], str[str.size()-1]);
	state = 1;
      } else if (state == 1) {
	swap (str[i], str[str.size()-1]);
	maxi = str;
	if (str[i] > str[str.size()-1])
	  break;
	swap (str[i], str[str.size()-1]);
      }
    }
  }

  if (maxi == "0")
    cout << "-1\n";
  else
    cout << maxi << '\n';

  return 0;
}
