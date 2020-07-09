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

string mat[][2] = {{"brasil", "Feliz Natal!"},
		   {"alemanha", "Frohliche Weihnachten!"},
		   {"austria", "Frohe Weihnacht!"},
		   {"coreia", "Chuk Sung Tan!"},
		   {"espanha", "Feliz Navidad!"},
		   {"grecia", "Kala Christougena!"},
		   {"estados-unidos", "Merry Christmas!"},
		   {"inglaterra", "Merry Christmas!"},
		   {"australia", "Merry Christmas!"},
		   {"portugal", "Feliz Natal!"},
		   {"suecia", "God Jul!"},
		   {"turquia", "Mutlu Noeller"},
		   {"argentina", "Feliz Navidad!"},
		   {"chile", "Feliz Navidad!"},
		   {"mexico", "Feliz Navidad!"},
		   {"antardida", "Merry Christmas!"},
		   {"canada", "Merry Christmas!"},
		   {"irlanda", "Nollaig Shona Dhuit!"},
		   {"belgica", "Zalig Kerstfeest!"},
		   {"italia", "Buon Natale!"},
		   {"libia", "Buon Natale!"},
		   {"siria", "Milad Mubarak!"},
		   {"marrocos", "Milad Mubarak!"},
		   {"japao", "Merii Kurisumasu!"}};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  while (cin >> s) {
    bool ok = false;
    for (int i = 0; i < 24; i++) {
      if (mat[i][0] == s) {
	cout << mat[i][1] << '\n';
	ok = true;
	break;
      }
    }
    if (!ok)
      cout << "--- NOT FOUND ---\n";
  }
  
  return 0;
}
