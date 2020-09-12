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

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 5e5 + 10;
int x[N], p[N], n;
long double prob[N], ans;

void brute(int i, long double sum, long double pp)
{
	if(i == n) ans += (sum / n) * pp;
	else
	{
		brute(i + 1, sum + sum + x[p[i]], pp * prob[p[i]]);
		brute(i + 1, sum + sum, pp * (1 - prob[p[i]]));
	}
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n;

	iota(p, p + n, 0);
	for(int i = 0; i < n; i++)
		cin >> x[i] >> prob[i];

	auto test = [&](int i, int j)
	{
		return ((2 * x[i] + x[j]) * prob[i] * prob[j]) + 
				(2 * x[i] * prob[i] * (1 - prob[j])) +
				(x[j] * (1 - prob[i]) * prob[j]);
	};

	sort(p, p + n, [&](int i, int j){ return test(i, j) < test(j, i);});

	long double ans2 = 0;
	ld ans3 = 0;
	for(int i = 0; i < n; i++) {
		ans2 = (ans2 + x[p[i]]) * prob[p[i]] + ans2 * (1 - prob[p[i]]);
		ans3 += ans2;
		// cout << i << ' ' << ans2 << '\n';
	}

	cout << fixed << ans3 / n << endl;

	// long double ans2 = 0;
	// ans2 = 1e18;
	// do
	// {
	// 	ans = 0;
	// 	brute(0, 0, 1);
	// 	ans2 = min(ans, ans2);
	// 	if(ans2 == ans)
	// 	for(int i = 0; i < n; i++)
	// 		cout << p[i] << " \n"[i == n - 1];
	// }while(next_permutation(p, p + n));

	// cout << fixed << ans2 << endl;

	return 0;
}
