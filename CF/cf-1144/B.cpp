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

vector<int> vec[2], vec2[2];
int x;

int main () {
    int n;
    cin >> n;
    while (n--) {
        cin >> x;
        vec[x%2].push_back (x);
        vec2[x%2].push_back (x);
    }
    sort (vec[0].begin(), vec[0].end());
    sort (vec[1].begin(), vec[1].end());
    
    int l1 = len (vec[0]);
    int l2 = len (vec[1]);
    if (l1 == l2 or l1 == l2-1 or l1-1 == l2)
        cout << "0\n";
    else {
        ll ans = 0;
        if (l1 > l2) {
            for (int i = 0; i < l1-l2-1; i++)
                ans += vec[0][i];
        } else {
            for (int i = 0; i < l2-l1-1; i++)
                ans += vec[1][i];
        }
        cout << ans << '\n';
    }

	return 0;
}
