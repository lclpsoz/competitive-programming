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

const int MAXT = 1e6+10;
const int fg = 'z'-'a'+1;

int n;
int trie[MAXT][27];
char arr[105];
int lst = 2;

void ins (int p = 0, int l = 1) {
  if (arr[p] == '\0') {
    trie[l][fg] = p;
    return;
  }
  char c = arr[p]-'a';
  if (!trie[l][c]) {
    trie[l][c] = lst;
    ins (p+1, lst++);
  } else
    ins (p+1, trie[l][c]);
}

pii prefix (int l) {
  pii p = {0, 0}, r;
  if (trie[l][fg]) {
    ++p.x;
    p.y = trie[l][fg];
  }
  for (int i = 0; i < fg; ++i)
    if (trie[l][i]) {
      r = prefix (trie[l][i]);
      p.x += r.x;
      p.y = max (p.y, r.y);
    }
  
  return p;
}

pii func (int p = 0, int l = 1) {
  if (arr[p] == '\0')
    return prefix (l);
  char c = arr[p]-'a';
  if (!trie[l][c])
    return {-1, -1};
  return func (p+1, trie[l][c]);
}

int main ()
{
  cin >> n;
  while (n--) {
    scanf ("%s", arr);
    ins();
  }
  /*for (int i = 0; i < fg; i++)
    printf ("%2c ", i+'a');
  putchar ('\n');
  for (int i = 1; i < lst; i++) {
    for (int j = 0; j <= fg; j++)
      printf ("%2d ", trie[i][j]);
    putchar ('\n');
    }*/

  cin >> n;
  while (n--) {
    scanf ("%s", arr);
    pii p = func ();
    if (p.x == -1)
      printf ("-1\n");
    else
      printf ("%d %d\n", p.x, p.y);
  }
  
  return 0;
}
