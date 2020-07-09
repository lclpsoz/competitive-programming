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
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int main () {
    int k, a, b, v;
    cin >> k >> a >> b >> v;
    int ans;
    for (ans = 1; a > 0; ans++) {
        int secs = min (k, b+1);
        b -= secs-1;
        a -= secs*v;
//         cout << "a: " << a << " | b: " << b << '\n';
    }
    cout << ans-1 << '\n';
    

	return 0;
}
