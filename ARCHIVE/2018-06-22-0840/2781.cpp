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

int n, m;

const int MAXN = 1010;

int arr[MAXN];

int main ()
{
	int a, b, v;
	cin >> m >> n;
	int sum = 0;
	while (m--) {
		scanf ("%d %d %d", &a, &v, &b);
		arr[a]-=v;
		arr[b]+=v;
		sum += v;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (arr[i] > 0)
			ans += arr[i];

	if (ans < sum)
		putchar ('S');
	else
		putchar ('N');
	printf ("\n%d\n", ans);

	return 0;
}
