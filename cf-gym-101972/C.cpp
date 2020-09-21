#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
////////////// Prewritten code follows. Look down for solution. ////////////////
//#define x first
//#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

const double EPS = 1e-10;
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

double a, b, c;

double f(double x) {
    return sqrt((b+c)*(b+c) + (a-x)*(a-x)) + sqrt(c*c + x*x);
}


int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);

    int t;
    int ia, ib, ic, ip;
    cin >> t;
    while (t--) {
        cin >> ia >> ib >> ic >> ip;
        a = ia, b = ib, c = ic;
        double l = 0, r = a, x_l, x_r;
        int qnt = 0;
        while(r-l > EPS && qnt++ < 100) {
            // cout << "l = " << l << ", r = " << r << '\n';
            x_l = (2*l + r)/3;
            x_r = (l + 2*r)/3;
            if(f(x_l) > f(x_r))
                l = x_l;
            else
                r = x_r;
        }
        // cout << "f_go:" << '\n';
        // for(ld i = 0.1; i < a; i+=0.1)
        //     cout << i << ' ' << f_go(i) << '\n';
        double p1 = f(l);
        

        // Remove percentage
        double a_p = (double)a*(double)ip/100.0;
        double b_p = (double)b*(double)ip/100.0;
        double p2 = sqrt(a_p*a_p + b_p*b_p);
        a *= (100-ip)/100.0;
        b *= (100-ip)/100.0;
        // cout << "a,b = " << a << ' ' << b << '\n';
        l = 0, r = a;
        qnt = 0;
        while(r-l > EPS && qnt++ < 100) {
            // cout << "l = " << l << ", r = " << r << '\n';
            x_l = (2*l + r)/3;
            x_r = (l + 2*r)/3;
            if(f(x_l) > f(x_r))
                l = x_l;
            else
                r = x_r;
        }
        // cout << "p1 = " << p1 << '\n';
        // cout << "p2 = " << p2 << '\n';
        // cout << "p3 = " << f_back(l) << '\n';
        cout << p1+p2+f(l) << '\n';
    }

	return 0;
}
