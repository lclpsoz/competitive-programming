#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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

pii frac(int a, int b)
{
	int g = gcd(a, b);
	return pii(a / g, b / g);
}
pii operator * (pii a, pii b)
{
	return pii(a.first * b.first, a.second * b.second);
}
pii operator + (pii a, pii b)
{
	return frac(a.first * b.second + b.first * a.second, a.second * b.second);
}

const int N = 110;
pii dp[N][N][N];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int r, s, p;
	cin >> r >> s >> p;

	for(int i = N - 1; i >= 0; i--)
		for(int j = N - 1; j >= 0; j--)
			for(int k = N - 1; k >= 0; k--)
				dp[i][j][k] = frac(0, 1);

	dp[r][s][p] = frac(1, 1);

	for(int i = r; i >= 0; i--)
		for(int j = s; j >= 0; j--)
			for(int k = p; k >= 0; k--)
			{
				int qq = (i > 0) + (j > 0) + (k > 0);
				if(qq <= 1) continue;
				int t = i + j + k + 1;
				int p1 = (i*j);
				int p2 = (j*k);
				int p3 = (k*i);
				int norm = p1+p2+p3;
				if(i)
					dp[i-1][j][k] = dp[i-1][j][k]+dp[i][j][k] * frac(p3,norm);
				if(j)
					dp[i][j-1][k] = dp[i][j-1][k]+dp[i][j][k] * frac(p1,norm);
				if(k)
					dp[i][j][k-1] = dp[i][j][k-1]+dp[i][j][k] * frac(p2,norm);
				// cout << i << " " << j << " " << k << ": " << dp[i][j][k].first << " / " << dp[i][j][k].second << endl;
			}
	
	double a = 0, b = 0, c = 0;
	for(int i = r; i > 0; i--)
		a += (double)dp[i][0][0].first / dp[i][0][0].second;
	for(int j = s; j > 0; j--)
		b += (double)dp[0][j][0].first / dp[0][j][0].second;
	for(int k = p; k > 0; k--)
		c += (double)dp[0][0][k].first / dp[0][0][k].second;
	double t = a + b + c;
	// double t = 1;
	cout << fixed << a / t << " " << b / t << " " << c / t << endl;

	return 0;
}
