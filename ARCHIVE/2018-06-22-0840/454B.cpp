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

int n;
int x;
vector<int> v;

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		v.pb (x);
	}
	bool t = false;
	int p = -1;
	if (v[n-1] > v[0]) {
		p = 0;
		t = true;
	}
	for (int i = 1; i < n; i++)
		if (v[i-1] > v[i]) {
			t = true;
			if (p != -1) {
				printf ("-1\n");
				return 0;
			} else
				p = n-i;
		}
	if (!t) p = 0;
	cout << p << '\n';


	return 0;
}
