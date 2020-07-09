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

const int N = sqrt(1e12+100);

ll n;
vector<ll> divisores;
vector<int> primos;
bool nao_primo[N];

void funcDivisores () {
  int s = (int)sqrt(n);
  for (int i = 2; i <= s; i++)
    if (n%i == 0) {
      //cout << i << endl;
      divisores.pb (i);
      if (i != s) {
	//printf ("  %lld\n", n/i);
	divisores.pb(n/i);
      }
    }
}

int desp (ll x) {
  int s = sqrt(x);
  if (s*1LL*s == x) return false;
  int qnt = 0;
  for (int i = 2; i <= s; i++)
    if (!nao_primo[i] && x%i == 0) {
      if ((x/i)%i == 0) {
	//printf ("||%d\n", i);
	return false;
      }
      else {
	qnt+=2;
      }
    }
  //printf ("%lld: %d\n", x, qnt);
  //printf ("           %10lld:  %s\n", x, qnt >= 2 ? "SIM" : "NAO||||||");
  return qnt >= 2;
}

int main ()
{
  int p = 2;
  for (; p*p < N; p++)
    if (!nao_primo[p])
      for (int i = p*p; i < N; i += p)
	nao_primo[i] = true;
  /*for (int i = 2; i<= 100; i++)
    if (nao_primo[i])
    printf ("%3d: %d\n", i, desp(i));*/
  
  scanf ("%lld", &n);
  funcDivisores();
  int ans = 0;
  bool me = !divisores.empty();
  for (ll x : divisores) {
    if ((n/x)%x == 0)
      me = false;
    if (desp (x))
      ans++;
  }
  ans+=me;

  printf ("%d\n", ans);
  
  return 0;
}
