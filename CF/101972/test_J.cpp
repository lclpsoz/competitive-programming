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

int calc(int i, int j) {
    if (j <= -1 || j > i) return 0;
    if (i == 0 && j == 0) return 1;
    return calc(i - 1, j - 1) + calc(i - 1, j);
}

int fac(int n) {
    if (n == 0) return 1;
    return n * fac(n - 1);
}

int comb(int n, int m) {
    return fac(n) / (fac(m) * fac(n - m));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);
	
	for (int i = 0; i <= 12; i++) {
        cout << calc(12, i) << endl;
        cout << comb(12, i) << endl;
    }
	
	return 0;
}