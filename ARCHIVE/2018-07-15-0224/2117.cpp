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

int n, m;
int qnt[30];
char arr[200];

int brute (int p, int qnt) {
  
}

int main ()
{
  scanf ("%d %d", &n, &m);
  while (n--) {
    scanf ("%[^\n]", arr);
    for (int i = 0; arr[i] != '\0'; i++)
      qnt[tolower(arr[i])-'a']++;
  }

  printf ("%d\n", brute (0, 0));
  
  return 0;
}
