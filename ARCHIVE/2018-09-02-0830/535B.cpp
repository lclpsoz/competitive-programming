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

int solv () {
  string s = "0";
  int p = 1;
  int lst = 0;
  while (s != str) {
    //cout << s << ' ' << str << '\n';
    if (s[lst] == '0') {
      s[lst] = '1';
    } else {
      s[lst] = '0';
      int aux = lst-1;
      while (aux >= 0) {
	if (s[aux] == '0') {
	  s[aux] = '1';
	  break;
	}
	s[aux] = '0';
	--aux;
      }
      //printf ("aux: %d\n", aux);
      if (aux == -1) {
	s = "0" + s;
	++lst;
      }
    }
    ++p;
  }

  return p;
}


int main ()
{
  cin >> str;
  for (char &c : str)
    c = (c == '4') ? '0' : '1';
  //cout << str << '\n';
  printf ("%d\n", solv());
  
  return 0;
}
