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

char str[20];
int arr[11];

int main ()
{
  int n;
  scanf ("%d", &n);
  scanf ("%s", str);
  for (int i = 0; str[i] != '\0'; i++)
    if (str[i] == '1' || str[i] == '0') {
    } else if (str[i] == '4') {
      arr[3]++;
      arr[2]+=2;
    } else if (str[i] =='6') {
      arr[5]++;
      arr[3]++;
    } else if (str[i] == '8') {
      arr[2] += 3;
      arr[7]++;
    } else if (str[i] == '9') {
      arr[7]++; arr[3] += 2; arr[2]++;
    } else
      arr[str[i]-'0']++;

  for (int i = 9; i >= 0; i--)
    while (arr[i]) {
      putchar (i+'0');
      --arr[i];
    }
  putchar ('\n');

  return 0;
}
