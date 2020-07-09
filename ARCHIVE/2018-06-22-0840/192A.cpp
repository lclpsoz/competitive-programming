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
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

vector<int> v;

int main ()
{
	int n;
	for (int i = 1, j = 2; i < 1e9; i+=j, j++)
		v.pb (i);

	int l = 0;
	int r = v.size()-1;
	scanf ("%d", &n);
	while (l <= r) {
		if (v[l]+v[r] > n)
			r--;
		else if (v[l]+v[r] < n)
			l++;
		else
			break;
	}
	// printf ("%d %d\n", l, r);
	if (l <= r)
		printf ("YES\n");
	else
		printf ("NO\n");


	return 0;
}
