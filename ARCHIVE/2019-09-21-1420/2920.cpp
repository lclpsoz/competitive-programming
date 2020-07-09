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

string s;
int k;

int main () {
    while (cin >> s >> k) {
        if (len (s) <= k)
            cout << '\n';
        else {
            for (int i = 0; i < len (s); i++)
                for (int j = 1; j <= k; j++)
                    if (s[i] > s[i+j]) {
                        k -= j;
                        for (int l = i; l < i+j; l++) s[l] = '-';
                    }
            for (int i = len (s)-1; i >= 0; i--) {
                if (!k) break;
                s[i] = '-';
            }
            for (char c : s)
                if (c != '-') cout << c;
            cout << '\n';
        }
    }

	return 0;
}
