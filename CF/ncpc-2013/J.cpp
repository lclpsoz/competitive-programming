#include <bits/stdc++.h>
using namespace std;

// --
#define x first
#define y second
#define len(x) ((int)x.size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
    return (int)(((x%m) + m)%m);
}
// --

const ld PI = acosl((ld)-1.0);
ld arr[10];
ld sum = 210.0 / 20.0;
ld pts[] = {0, 50, 25, sum, 3*sum, sum, 2*sum};
ld desv;

ld f(ld r) {
    return (2*PI*r)*(expl(-((r*r) / (2*desv*desv))) / (2*PI*desv*desv));
}

ld area(ld r) {
    return (PI*r*r);
}

ld simpson(ld a, ld b, int n = 1e6)
{
    ld h = (b - a) / n, s = f(a) + f(b);
    for(int i = 1; i < n; i += 2) s += 4 * f(a + h*i);
    for(int i = 2; i < n; i += 2) s += 2 * f(a + h*i);
    return s*h/3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;

    for(int i = 1; i < 7; i++) cin >> arr[i];
    cin >> desv;

    ld ans = 0;

    for(int i = 1; i < 7; i++)
    {
        // cout << "i = " << i << ' ' << "arr[i] = " << arr[i] << ' ' << "area = " << area(arr[i]) << '\n';
        ld now = simpson(arr[i-1], arr[i]);
        // cout << "now = " << now << '\n';
        ans += pts[i] * now;
    }

    cout << ans << '\n';

    return 0;
}