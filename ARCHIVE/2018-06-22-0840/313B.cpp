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

const int MAXN = 1e5+10;

int m;
int prefixSum[MAXN];
char str[MAXN];

int main ()
{
	scanf ("%s", str);
	int i =0;
	for (; str[i+1] != '\0'; i++) {
		prefixSum[i] = prefixSum[i-1];
		if (str[i] == str[i+1])
			prefixSum[i]++;
	}
	prefixSum[i] = prefixSum[i-1];

	cin >> m;
	int l, r;
	while (m--) {
		scanf ("%d %d", &l, &r);
		printf ("%d\n", prefixSum[r-2]-prefixSum[l-2]);
	}

	return 0;
}
