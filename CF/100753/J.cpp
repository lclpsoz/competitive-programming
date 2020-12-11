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



int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int g, c, n;
    cin >> g >> c >> n;
    int t[n], p[n], s[n];
    for (int i = 0; i < n; i++) {
    	string rounding;
    	cin >> rounding;
    	int type = 0;
    	if (rounding.compare("honest") == 0)
    		type = 1;
    	else if (rounding.compare("generous") == 0)
    		type = 2;
    	int pi, si;
    	cin >> pi >> si;
    	
    	t[i] = type;
    	p[i] = pi;
    	s[i] = si;
    }

    int dp[c + 1][g * n + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= c; i++)
        for (int j = 0; j <= g * n; j++)
            ;//dp[i][j] = -200;
    dp[0][c] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= c; j++) {
            for (int k = 0; k <= g * n; k++) {
                int need = k + s[i];
                if (need <= g * n)
                    dp[j][k] = max(dp[j][k], dp[j][k + need] + 1);
                if (j) {
                    bool buy = false;
                    int troco = (g - s[i]) / p[i];
                    bool igual = ((g - s[i]) % p[i] == 0);
                    if (t[i] == 0 && troco == k)
                        buy = true;
                    else if (t[i] == 1 && troco + igual == k)
                        buy = true;
                    else if (t[i] == 2 && troco + 1 - igual == k)
                    if (buy)
                        dp[j][k] = max(dp[j][k], dp[j - 1][k] + 1);
                }
            }
        }
    }
    

	return 0;
}
