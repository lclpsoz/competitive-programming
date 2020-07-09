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

int t, n;
map<string, double> preco;

int main () {
    cin.tie (0);
    ios::sync_with_stdio (0);
    cout << fixed;
    cout << setprecision (2);
    
    cin >> t;
    while (t--) {
        preco.clear();
        cin >> n;
        while (n--) {
            string str;
            double val;
            cin >> str >> val;
            preco[str] = val;
        }
        cin >> n;
        double ans = 0;
        while (n--) {
            string str;
            int qnt;
            cin >> str >> qnt;
            ans += preco[str]*qnt;
        }
        cout << "R$ " << ans << '\n';
    }

    return 0;
}
