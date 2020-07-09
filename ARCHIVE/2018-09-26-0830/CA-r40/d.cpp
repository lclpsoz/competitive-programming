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

const int MAXN = 2010;

int n;
int arr[MAXN];
int all[MAXN];
int per[MAXN];

bool check () {
	for (int i = 0; i < n; i++)
		for (int 
}

void ger (int p) {
	if (p == n) {
	} else {
		for (int i = 0; i < n; i++)
			if (all[i] != -1) {
				int aux = all[i];
				all[i] = -1;
				per[p] = all[i];
				ger (p+1);
				all[i] = aux;
			}
	}
}

int main ()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		all[i] = i+1;
	for (int i = 0; i < n; i++)
		scanf ("%d", &arr[i]);
	for (int 

	return 0;
}
