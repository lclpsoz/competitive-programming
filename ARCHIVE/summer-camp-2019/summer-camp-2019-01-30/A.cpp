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

const int N = 1e5+10;

int n;
int a[N];

int main () {
    cin.tie (0);
    ios::sync_with_stdio(false);
    string str;
    while (getline (cin, str)) {
        istringstream vals (str);
        int ans = 0;
        int maxi = 0;
        int x;
        while (vals >> x) {
//             cout << x << '\n';
            if (maxi + x < x)
                maxi = x;
            else
                maxi = maxi + x;
            ans = max (maxi, ans);
//             cout << x << '\n';
        }
        cout << ans << '\n';
    }

	return 0;
}
