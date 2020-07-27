#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vpii = vector<pii>;

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);
	
	int n, m;
	cin >> n >> m;

	ll sa = 0, sb = 0;
	vi a(n), b(m);
	for(int& i : a) cin >> i, sa += i;
	for(int& i : b) cin >> i, sb += i;
	
	sort(ALL(a), greater<int>());
	sort(ALL(b), greater<int>());

	vector<ll> sum2(n + 1, 0);
	vector<ll> sum1(m + 1, 0);

	for(int i = n - 1; i >= 0; i--)
		sum1[i] = sum1[i + 1] + a[i];

	for(int i = m - 1; i >= 0; i--)
		sum2[i] = sum2[i + 1] + b[i];
	
	ll ans = INF<ll>;
	for(int i = 0; i < n; i++)
		ans = min(ans, sb * (i + 1LL) + sum1[i + 1]);
	for(int i = 0; i < m; i++)
		ans = min(ans, sum2[i + 1] + sa * (i + 1LL));
	
	cout << ans << endl;

	return 0;
}