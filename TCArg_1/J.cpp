#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d, a, b;
	cin >> n >> d >> a >> b;
	vector<int> p(n), x(n), y(n);
	iota(p.begin(), p.end(), 0);
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	sort(p.begin(), p.end(), [&](int i, int j){
		return x[i] * a + y[i] * b < x[j] * a + y[j] * b;
	});

	vector<int> ans;

	for(int i = 0; i < n && d >= 0; i++)
	{
		ans.emplace_back(p[i] + 1);
		d -= x[p[i]] * a + y[p[i]] * b;
	}

	if(d < 0) ans.pop_back();

	cout << ans.size() << endl;
	for(int i : ans) cout << i << " ";

	return 0;
}
