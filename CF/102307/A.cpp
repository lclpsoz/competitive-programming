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

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	vector<vector<int>> line(n, vector<int>(4));
    	map<pii, int> m;
    	map<pair<pair<int, int>, pair<int, int>>, bool> m2;
    	int count = 0;
    	for (int i = 0; i < n; i++) {
    		int a, b, c, d;
    		cin >> a >> b >> c >> d;
    		line[i][0] = a;
    		line[i][1] = b;
    		line[i][2] = c;
    		line[i][3] = d;

    		int num = abs(b - d);
    		int denom = abs(a - c);
    		int tmp = num;
    		num /= gcd(num, denom);
    		denom /= gcd(tmp, denom);

    		pii coef_line;
    		if (num == 0)
    			coef_line = {b, b};
    		else if (denom == 0)
    			coef_line = {a, a};
    		else
    			coef_line = {(-num * a + denom * b) / gcd(abs(-num * a + denom * b), denom), denom / gcd(abs(-num * a + denom * b), denom)};

    		if (a > c && b < d || c > a && d < b || denom == 0)
    			num *= -1;
    		pii coef_ang = {num, denom};
    		int test_num = abs(b - d);
    		int test_denom = abs(a - c);

    		//cout << coef_ang.first << " " << coef_ang.second << endl;
    		if (!m2[{coef_ang, coef_line}]) {
    			m[coef_ang]++;
    			m2[{coef_ang, coef_line}] = true;
    		}
    	}
    	//assert(count == n);
    	int ans = 0;
	    for (int i = 0; i < n; i++) {
	    	int a = line[i][0];
	    	int b = line[i][1];
	    	int c = line[i][2];
	    	int d = line[i][3];

	    	int num = abs(b - d);
	    	int denom = abs(a - c);
	    	int fac = 1;
    		if (a > c && b < d || c > a && d < b || denom == 0)
    			fac = -1;
    		if (m[{fac * (num / gcd(num, denom)), denom / gcd(num, denom)}] > 0) {
	    		m[{fac * (num / gcd(num, denom)), denom / gcd(num, denom)}]--;
	    		fac = -fac;
	    		ans += m[{fac * denom / gcd(denom, num), num / gcd(denom, num)}];
	    	}
	    }
	    cout << ans << endl;
    }


	return 0;
}
