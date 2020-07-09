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

const int MAXN = 2e5+10;
char arr[MAXN];
int dp[MAXN][4][2];

int func (int p, int acu, bool cut) {
	int &r = dp[p][acu][cut];
	// printf ("%d %d %d\n", p, acu, cut);
	if (r != -1)
		return r;
	r = 0;
	if (cut) {
		if (!acu) r = 1;
		acu = 0;
	}
	if (arr[p] == '-')
		return r;
	r += max (func (p+1, (acu+arr[p])%3, true), func (p+1, (acu+arr[p])%3, false));
	return r;
}

int main ()
{
	memset (dp, -1, sizeof (dp));
	scanf ("%s", arr);
	arr[strlen(arr)] = '-';
	for (int i = 0; arr[i] != '-'; i++)
		arr[i] = (arr[i]-'0')%3;
	printf ("%d\n", func (0, 0, false));

  return 0;
}
