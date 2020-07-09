#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int m, n;

ll pow_p (int a, int b) {
	ll r = 1;
	while (b--)
		r *= a;

	return r;
}

int main ()
{
	scanf ("%d %d", &m, &n);

	double ans = 0;
	double bef = 0;
	double acu = 0;
	double div = pow(m,n);
	for (int i = 1; i <= m; i++) {
		bef = pow (i, n)/div - acu;
		acu += bef/div;
		ans += (i*bef)/div;
		printf ("|%lf %lf\n", bef, ans);
	}

	// printf ("%lf\n", ans);
	printf ("%lf\n", ans/pow(m,n));

	return 0;
}
