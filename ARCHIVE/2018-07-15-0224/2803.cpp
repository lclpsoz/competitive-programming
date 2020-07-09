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

char mat[] = {" roraima acre amapa amazonas para rondonia tocantins  "};
char arr[200];
  
int main ()
{
  scanf ("%s", arr+1);
  arr[0] = ' ';
  int ss = strlen(arr);
  arr[ss] = ' ';
  for (int i = 0, j = 0; mat[i] != '\0'; i++)
    if (mat[i] == arr[j])
      j++;
    else if (arr[j] == '\0') {
      printf ("Regiao Norte\n");
      return 0;
    }
    else
      j = 0;

  printf ("Outra regiao\n");
  
  return 0;
}
