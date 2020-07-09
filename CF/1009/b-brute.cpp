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

char arr[MAXN];

int main ()
{
	scanf ("%s", arr);
	for (int i = 1; arr[i] != '\0'; i++)
		if (arr[i-1] == '1' && arr[i] == '0' || arr[i-1] == '2' && arr[i] == '1') {
			int j = i;
			while (j >= 0 && (arr[j-1] == '1' && arr[j] == '0' || arr[j-1] == '2' && arr[j] == '1')) {
				swap (arr[j-1], arr[j]);
				--j;
			}
		}
	printf ("%s\n", arr);

  return 0;
}
