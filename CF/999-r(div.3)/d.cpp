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

const int MAXN = 2e5+10;

int n, m;
int arr[MAXN], qnt[MAXN], rest[MAXN], nec[MAXN];
set<int> prec;

int main ()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &arr[i]);
		rest[i] = arr[i]%m;
		qnt[rest[i]]++;
	}

	int rem = n/m;
	for (int i = 0; i < m; i++)
		if (qnt[i] < rem)
			prec.insert (i);

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (qnt[rest[i]] > rem) {
			auto it = prec.lower_bound (rest[i]);
			if (it == prec.end())
				it = prec.begin();
			qnt[rest[i]]--;
			qnt[*it]++;
			int re = *it;
			if (qnt[*it] == rem)
				prec.erase (it);
			if (re-rest[i] < 0) {
				arr[i] += re-rest[i]+m;
				ans += re-rest[i]+m;
			} else {
				arr[i] += re-rest[i];
				ans += re-rest[i];
			}
		}
	}
	printf ("%lld\n", ans);
	for (int i = 0; i < n; i++)
		printf ("%d ", arr[i]);
	putchar ('\n');


	return 0;
}
