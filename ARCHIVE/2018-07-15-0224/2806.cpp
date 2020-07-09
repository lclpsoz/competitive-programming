#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

int n, k;
set<string> s;
string str;
char arr[55];
bool ans[105];
string in[105];
vector<string> ent[105];

int main ()
{
  string sss = "abcdef";
  scanf ("%d", &n);
  while (n--) {
    scanf ("%s", arr);
    //   for (int i = 0; arr[i] != '\0'; i++)
    //    arr[i] = tolower (arr[i]);
    s.insert (arr);
  }
  scanf ("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf ("%s %d", arr, &k);
    in[i] = arr;
    while (k--) {
      scanf ("%s", arr);
      ent[i].pb (arr);
    }
  }
  
  for (int i = 1; i <= n; i++) {
    bool tst = false;
    for (int j = 1; j <= n; j++) {
      if (!ans[j]) {
	int qnt = 0;
	for (string ss : ent[j])
	  if (s.count(ss))
	    qnt++;
	if (qnt > ent[j].size()/2) {
	  ans[j] = true;
	  s.insert (in[j]);
	  tst = true;
	}
      }
    }
    if (!tst)
      break;
  }

  for (int i = 1; i <= n; i++)
    if (ans[i])
      printf ("porcao tipica\n");
    else
      printf ("porcao comum\n");
  
  return 0;
}
