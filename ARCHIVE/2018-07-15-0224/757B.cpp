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

int n;
set<int> s;
bool not_prime[MAXN];
vector<int> primes;
int qnt[MAXN];
vector<int> arr[MAXN];

void fatoracao (int val) {
  if (val == 1) {
    qnt[1] = 1;
    return;
  }
  int sq = sqrt(val);
  if (arr[val].empty()) {
    int i = 0;
    int x = val;
    while (x > 1 && primes[i] <= sq) {
      if (x % primes[i] == 0)
	arr[val].pb (primes[i]);
      while (x % primes[i] == 0)
	x /= primes[i];
      ++i;
    }
    if (x > 1)
      arr[val].pb (x);
  }
  for (int xx : arr[val])
    ++qnt[xx];
}

int main ()
{
  cin >> n;
  int x;
  int i;
  for (i = 2; i*i < MAXN; i++)
    if (!not_prime[i]) {
      for (int j = i*i; j < MAXN; j+=i)
	not_prime[j] = true;
      primes.pb (i);
    }
  for (; i < MAXN; i++)
    if (!not_prime[i])
      primes.pb (i);
  while (n--) {
    scanf ("%d", &x);
    fatoracao (x);
  }
  int ans = 0;
  for (int i = 0; i < MAXN; i++)
    ans = max (ans, qnt[i]);
  cout << ans << '\n';

  return 0;
}
