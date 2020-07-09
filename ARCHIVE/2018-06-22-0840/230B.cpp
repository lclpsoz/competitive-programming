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

const int MAXN = 2e6+10;

bool not_prime[MAXN];
vector<ll> v;

int main ()
{
	not_prime[0] = not_prime[1] = true;
	int i = 2;
	for (i = 2; i*i < MAXN; i++)
		if (!not_prime[i]) {
			v.pb (1LL*i*i);
			for (int j = i*i; j < MAXN; j+=i)
				not_prime[j] = true;
		}
	for (; i < MAXN; i++)
		if (!not_prime[i])
			v.pb (1LL*i*i);
	int n;
	ll a;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%lld", &a);
		auto it = lower_bound (v.begin(), v.end(), a);
		if (*it == a)
			printf ("YES\n");
		else
			printf ("NO\n");
	}

	return 0;
}
