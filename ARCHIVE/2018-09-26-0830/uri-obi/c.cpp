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

const int N = 1e5+10;

char key[100];
char str[N];
char mat[30][30];
int n;

bool func (char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return true;
  return false;
}

int main ()
{
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++)
      mat[i][j] = (i+j)%26;
  scanf ("%s", key);
  int sz = strlen (key);
  scanf ("%d", &n);
  //scanf ("%[^\n]", str);
  getchar ();
  bool vogal = false;
  while (n--) {
    scanf ("%[^\n]", str);
    getchar();
    vogal = false;
    for (int i = 0, j = 0; str[i] != '\0'; i++)
      if (str[i] == ' ') {
	putchar (' ');
	vogal = false;
      }
      else if (vogal || ((i == 0 || str[i-1] == ' ') && func (str[i]))) {
	vogal = true;
	putchar (str[i]);
      }
      else {
	putchar ('a' + mat[str[i]-'a'][key[j%sz]-'a']);
	j++;
      }
    putchar ('\n');
  }
  
  return 0;
}
