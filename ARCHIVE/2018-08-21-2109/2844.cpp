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

const int N = 1e5+100;

char a[N];

int main ()
{
  int Am, Rm, Em, Av, Rv, Ev;
  cin >> Am >> Rm >> Em;
  scanf ("%d %d %d", &Av, &Rv, &Ev);
  getchar ();
  scanf ("%[^\n]", a);
  int n = strlen (a);
  int m = 2*Am + Rm + n*Em;
  int v = 2*Av + Rv + n*Ev;
  //printf ("%d %d\n", m, v);
  if (m < v)
    printf ("Matheus\n");
  else if (m > v)
    printf ("Vinicius\n");
  else
    printf ("Empate\n");

  return 0;
}
