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

string trash, str;
string a[10];
int qnt[5];

int main () {
    int n;
    cin >> n;
    cin >> trash;
    int mx = 0;
    while (n--) {
        getline (cin, trash);
        for (int i = 0; i < 4; i++) {
            getline (cin, a[i]);
            //cout << a[i] << '\n';
        }
        getline (cin, trash);
        for (int i = 0; i < 4; i++) {
            getline (cin, str);
            if (str != a[i]) ++qnt[i];
            mx = max (mx, qnt[i]);
        }
    }
    vector<int> ans;
    for (int i = 0; i < 4; i++)
        if (qnt[i] == mx) ans.push_back (i);
    for (int i = 0; i < len (ans); i++)
        printf ("%d%c", ans[i]+1, " \n"[i==len(ans)-1]);

	return 0;
}
