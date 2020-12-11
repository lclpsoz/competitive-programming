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

const int MAXV = 1000000;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(ll & x, ll & y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll find_all_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    ll x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    ll lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    ll rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    ll lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    ll rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    // return (rx - lx) / abs(b) + 1;
	return lx + 1000000000;
}

bool solve(int n, int k) {
	for(int num_pos = 1; num_pos < n; num_pos++) {
		int a = n-num_pos;
		int b = -n;
		int num_neg = a;
		ll x = find_all_solutions(a, b, k, 1, MAXV*num_pos, 1, MAXV*num_neg);
		if(x == 0) break;
		x -= 1000000000;
		assert(x >= 1 and x <= MAXV*num_pos);
		int q = (k-(a*x))/b;
		assert(q >= 1 and q <= MAXV*num_neg);
		int used_neg = (q+MAXV)/MAXV;
		int used_pos = (x+MAXV)/MAXV;
		vi ans;
		for(int i = 0; i < n-used_neg-used_pos; i++)
			ans.push_back(0);
		while(q) {
			ans.push_back(-min(MAXV, q));
			// cout << "val = " << q << '\n';
			q -= -ans.back();
		}
		while(x) {
			ans.push_back((int)min((ll)MAXV, x));
			x -= ans.back();
		}
		assert(LEN(ans) == n);
		cout << n << '\n';
		for(int i = 0; i < n; i++)
			cout << ans[i] << " \n"[i==n-1];
		return true;
	}
	return false;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		int k, l;
		cin >> k >> l;
		if(l == 0 or l > 1999)
			cout << "-1\n";
		else if(l == 1) {
			if(k > 1000000)
				cout << "-1\n";
			else
				cout << -k << '\n';
		}
		else {
			bool ans = false;
			for(int n = l; n <= 1999; n++) {
				// Ideia de Ilmar
				// if(n%2 == 1 and k%(n-1) == 0 and k/(n-1) <= MAXV) {
				// 	// cout << "Ilmar\n";
				// 	cout << n << '\n';
				// 	k/=(n-1);
				// 	for(int i = 0; i < n; i++) {
				// 		if(i) cout << ' ';
				// 		if(i%2)
				// 			cout << -k;
				// 		else
				// 			cout << k;
				// 	}
				// 	cout << '\n';
				// 	ans = true;
				// 	break;
				// }
				ans = solve(n, k);
				if(ans) break;
			}
			if(!ans)
				cout << "-1\n";
		}
	}

	return 0;
}
