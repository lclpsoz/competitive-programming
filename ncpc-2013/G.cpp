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

int n;

void yes() {
    cout << "Deletion succeeded\n";
}

void no() {
    cout << "Deletion failed\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s1, s2;
    cin >> n >> s1 >> s2;
    if(n%2 == 1)
        for(int i = 0; i < len(s1); i++)
            s1[i] = (!(s1[i]-'0'))+'0';
    s1 == s2 ? yes() : no();

    return 0;
}