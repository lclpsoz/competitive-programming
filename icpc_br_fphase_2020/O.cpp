#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

#define M_PI 3.14159265358979323846

struct pt
{
	int x, y;
};

int main ()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	cin >> n;
	vector<pt> ests(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		ests[i] = {x, y};
	}
	vector<double> cos_def(n), sen_def(n), dists(n);
	for (int i = 1; i < n; i++)
	{
		pt dir = {ests[i].x - ests[i - 1].x, ests[i].y - ests[i - 1].y};
		double hip = sqrt(dir.x * dir.x + dir.y + dir.y);
		cos_def[i - 1] = (double)dir.x / hip;
		sen_def[i - 1] = (double)dir.y / hip;
		dists[i - 1] = hip;
	}
	
	double K = 0, L = 0;
	for (int i = 0; i < n - 1; i++)
	{
		K += cos_def[i] * dists[i];
		L += sen_def[i] * dists[i];
	}
	
	double r = 1e9;
	for (double i = 0; i < 2 * M_PI; i += 0.01)
	{
		r = min(r, cos(i) * K - sin(i) * L);
	}
	cout << r << endl;

	return 0;
}
